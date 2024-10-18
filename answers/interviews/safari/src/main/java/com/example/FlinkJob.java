package com.example;

import org.apache.flink.api.common.eventtime.WatermarkStrategy;
import org.apache.flink.api.common.functions.MapFunction;
import org.apache.flink.api.java.tuple.Tuple2;
import org.apache.flink.api.java.tuple.Tuple4;
import org.apache.flink.connector.kafka.source.KafkaSource;
import org.apache.flink.connector.kafka.source.enumerator.initializer.OffsetsInitializer;
import org.apache.flink.streaming.api.datastream.ConnectedStreams;
import org.apache.flink.streaming.api.datastream.DataStream;
import org.apache.flink.streaming.api.environment.StreamExecutionEnvironment;
import org.apache.flink.streaming.api.functions.co.CoFlatMapFunction;
import org.apache.flink.streaming.api.functions.co.ProcessJoinFunction;
import org.apache.flink.streaming.api.windowing.time.Time;
import org.apache.flink.api.common.serialization.SimpleStringSchema;
import org.apache.flink.connector.jdbc.JdbcConnectionOptions.JdbcConnectionOptionsBuilder;
import org.apache.flink.connector.jdbc.JdbcSink;
import org.apache.flink.connector.jdbc.JdbcStatementBuilder;
import org.apache.flink.util.Collector;
import org.apache.flink.api.common.typeinfo.TypeHint;
import org.apache.flink.api.common.typeinfo.TypeInformation;

import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.time.Duration;

public class FlinkJob {
    public static void main(String[] args) throws Exception {
        final StreamExecutionEnvironment env = StreamExecutionEnvironment.getExecutionEnvironment();

        KafkaSource<String> aSource = createKafkaSource("localhost:9092", "a");
        KafkaSource<String> bSource = createKafkaSource("localhost:9092", "b");
        KafkaSource<String> cSource = createKafkaSource("localhost:9092", "c");
        KafkaSource<String> dSource = createKafkaSource("localhost:9092", "d");
        KafkaSource<String> eSource = createKafkaSource("localhost:9092", "e");

        WatermarkStrategy<Tuple2<Long, Integer>> aWatermark = WatermarkStrategy
                .<Tuple2<Long, Integer>>forBoundedOutOfOrderness(Duration.ofMillis(0));
        WatermarkStrategy<Tuple2<Long, Integer>> bWatermark = WatermarkStrategy
                .<Tuple2<Long, Integer>>forBoundedOutOfOrderness(Duration.ofMillis(100));
        WatermarkStrategy<Tuple2<Long, Float>> cWatermark = WatermarkStrategy
                .<Tuple2<Long, Float>>forBoundedOutOfOrderness(Duration.ofMillis(150));
        WatermarkStrategy<Tuple2<Long, Float>> dWatermark = WatermarkStrategy
                .<Tuple2<Long, Float>>forBoundedOutOfOrderness(Duration.ofMillis(1000));

        DataStream<Tuple2<Long, Integer>> aStream = createIntegerStream(env, aSource, aWatermark);
        DataStream<Tuple2<Long, Integer>> bStream = createIntegerStream(env, bSource, bWatermark);
        DataStream<Tuple2<Long, Float>> cStream = createFloatStream(env, cSource, cWatermark);
        DataStream<Tuple2<Long, Float>> dStream = createFloatStream(env, dSource, dWatermark);
        DataStream<Tuple2<Long, String>> eStream = createStringStream(env, eSource, WatermarkStrategy.noWatermarks());

        DataStream<Tuple2<Float, Float>> cdStream = cStream
                .keyBy(t -> 1)
                .intervalJoin(dStream.keyBy(t -> 1))
                .between(Time.milliseconds(-1000), Time.milliseconds(1000))
                .process(new ProcessJoinFunction<Tuple2<Long, Float>, Tuple2<Long, Float>, Tuple2<Float, Float>>() {
                    @Override
                    public void processElement(
                            Tuple2<Long, Float> c, Tuple2<Long, Float> d, Context ctx,
                            Collector<Tuple2<Float, Float>> out) {
                        out.collect(new Tuple2<>(c.f1, d.f1));
                    }
                }).returns(TypeInformation.of(new TypeHint<Tuple2<Float, Float>>() {}));
        DataStream<Tuple4<Integer, Integer, Float, String>> abStream = aStream
                .connect(bStream)
                .flatMap(new CoFlatMapFunction<Tuple2<Long, Integer>, Tuple2<Long, Integer>, Tuple4<Integer, Integer, Float, String>>() {
                    private Integer aStatus = 0;
                    private Integer bStatus = 0;

                    @Override
                    public void flatMap1(Tuple2<Long, Integer> a, Collector<Tuple4<Integer, Integer, Float, String>> out) {
                        aStatus = a.f1;
                    }

                    @Override
                    public void flatMap2(Tuple2<Long, Integer> b, Collector<Tuple4<Integer, Integer, Float, String>> out) {
                        bStatus = b.f1;
                        out.collect(new Tuple4<>(aStatus, bStatus, null, "pending"));
                    }
                }).returns(TypeInformation.of(new TypeHint<Tuple4<Integer, Integer, Float, String>>() {}));
        ConnectedStreams<Tuple4<Integer, Integer, Float, String>, Tuple2<Long, String>> abeStream = abStream.connect(eStream);
        DataStream<Tuple4<Integer, Integer, Float, String>> processedStream = abeStream
                .flatMap(new CoFlatMapFunction<Tuple4<Integer, Integer, Float, String>, Tuple2<Long, String>, Tuple4<Integer, Integer, Float, String>>() {
                    private String eEvent = "close";

                    @Override
                    public void flatMap1(Tuple4<Integer, Integer, Float, String> abStatus, Collector<Tuple4<Integer, Integer, Float, String>> out) {
                        out.collect(new Tuple4<>(abStatus.f0, abStatus.f1, abStatus.f2, eEvent));
                    }

                    @Override
                    public void flatMap2(Tuple2<Long, String> e, Collector<Tuple4<Integer, Integer, Float, String>> out) {
                        eEvent = e.f1;
                    }
                }).returns(TypeInformation.of(new TypeHint<Tuple4<Integer, Integer, Float, String>>() {}));
        DataStream<Float> resultStream = processedStream
                .connect(cdStream)
                .flatMap(new CoFlatMapFunction<Tuple4<Integer, Integer, Float, String>, Tuple2<Float, Float>, Float>() {
                    private Float cValue = 0.0f;
                    private Float dValue = 0.0f;

                    @Override
                    public void flatMap1(Tuple4<Integer, Integer, Float, String> status, Collector<Float> out) throws Exception {
                        if ("close".equals(status.f3)) {
                            return;
                        }

                        if (status.f0 == 1 && status.f1 == 1) {
                            out.collect(cValue + dValue);
                        } else if (dValue != 0) {
                            out.collect(cValue / dValue);
                        } else {
                            System.err.println("Division by zero encountered.");
                        }
                    }

                    @Override
                    public void flatMap2(Tuple2<Float, Float> cd, Collector<Float> out) {
                        cValue = cd.f0;
                        dValue = cd.f1;
                    }
                }).returns(TypeInformation.of(new TypeHint<Float>() {}));

        resultStream.addSink(JdbcSink.sink(
                "INSERT INTO results (result_value) VALUES (?)",
                new JdbcStatementBuilder<Float>() {
                    @Override
                    public void accept(PreparedStatement ps, Float value) throws SQLException {
                        ps.setFloat(1, value);
                    }
                },
                new JdbcConnectionOptionsBuilder()
                        .withUrl("jdbc:mysql://localhost:3306/mydb")
                        .withDriverName("com.mysql.cj.jdbc.Driver")
                        .withUsername("username")
                        .withPassword("password")
                        .build()
        ));

        env.execute("Kafka Flink Streaming Job");
    }

    private static KafkaSource<String> createKafkaSource(String bootstrapServers, String topic) {
        return KafkaSource.<String>builder()
                .setBootstrapServers(bootstrapServers)
                .setTopics(topic)
                .setGroupId("flink-group")
                .setStartingOffsets(OffsetsInitializer.earliest())
                .setValueOnlyDeserializer(new SimpleStringSchema())
                .build();
    }

    private static DataStream<Tuple2<Long, Integer>> createIntegerStream(
            StreamExecutionEnvironment env,
            KafkaSource<String> source,
            WatermarkStrategy<Tuple2<Long, Integer>> watermarkStrategy) {
        DataStream<String> kafkaStream = env.fromSource(source, WatermarkStrategy.noWatermarks(), "Kafka Source");
        return kafkaStream
                .map(new MapFunction<String, Tuple2<Long, Integer>>() {
                    @Override
                    public Tuple2<Long, Integer> map(String value) throws Exception {
                        Integer parsedValue = Integer.valueOf(value);
                        return new Tuple2<>(System.currentTimeMillis(), parsedValue);
                    }
                })
                .returns(TypeInformation.of(new TypeHint<Tuple2<Long, Integer>>() {}))
                .assignTimestampsAndWatermarks(watermarkStrategy);
    }

    private static DataStream<Tuple2<Long, Float>> createFloatStream(
            StreamExecutionEnvironment env,
            KafkaSource<String> source,
            WatermarkStrategy<Tuple2<Long, Float>> watermarkStrategy) {
        DataStream<String> kafkaStream = env.fromSource(source, WatermarkStrategy.noWatermarks(), "Kafka Source");
        return kafkaStream
                .map(new MapFunction<String, Tuple2<Long, Float>>() {
                    @Override
                    public Tuple2<Long, Float> map(String value) throws Exception {
                        Float parsedValue = Float.valueOf(value);
                        return new Tuple2<>(System.currentTimeMillis(), parsedValue);
                    }
                })
                .returns(TypeInformation.of(new TypeHint<Tuple2<Long, Float>>() {}))
                .assignTimestampsAndWatermarks(watermarkStrategy);
    }

    private static DataStream<Tuple2<Long, String>> createStringStream(
            StreamExecutionEnvironment env,
            KafkaSource<String> source,
            WatermarkStrategy<Tuple2<Long, String>> watermarkStrategy) {
        DataStream<String> kafkaStream = env.fromSource(source, WatermarkStrategy.noWatermarks(), "Kafka Source");
        return kafkaStream
                .map(new MapFunction<String, Tuple2<Long, String>>() {
                    @Override
                    public Tuple2<Long, String> map(String value) throws Exception {
                        return new Tuple2<>(System.currentTimeMillis(), value);
                    }
                })
                .returns(TypeInformation.of(new TypeHint<Tuple2<Long, String>>() {}))
                .assignTimestampsAndWatermarks(watermarkStrategy);
    }
}