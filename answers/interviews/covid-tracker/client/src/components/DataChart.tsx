import React from 'react';
import { LineChart, Line, BarChart, Bar, XAxis, YAxis, CartesianGrid, Tooltip, Legend, ResponsiveContainer } from 'recharts';
import ColumnType from '../types/ColumnType';
import DataType from '../types/DataType';
import ChartType from '../types/ChartType';

type DataChartProps = {
  data1: DataType[];
  data2?: DataType[];
  chartType: ChartType;
  selectedColumn: ColumnType;
};

const DataChart: React.FC<DataChartProps> = ({ data1, data2, chartType, selectedColumn }) => {
  if (!data1 || data1.length === 0) {
    return <div>No data available for selected filters.</div>;
  }

  const isComparison = data2 && data2.length > 0;

  const transformData = (data: DataType[]) => {
    return data.map((item) => ({
      name: item.date,
      value: isNaN(parseFloat(item[selectedColumn])) ? 0 : parseFloat(item[selectedColumn]),
    }));
  };

  const chartData1 = transformData(data1);
  const chartData2 = data2 ? transformData(data2) : [];

  const allDates = [
    ...chartData1.map((item) => item.name),
    ...chartData2.map((item) => item.name),
  ];

  const uniqueDates = Array.from(new Set(allDates)).sort(
    (a, b) => new Date(a).getTime() - new Date(b).getTime()
  );

  const fillMissingData = (data: { name: string; value: number }[]) => {
    const dataMap = new Map(data.map((item) => [item.name, item]));
    return uniqueDates.map((date) => {
      const item = dataMap.get(date);
      return item ? item : { name: date, value: 0 };
    });
  };

  const filledChartData1 = fillMissingData(chartData1);
  const filledChartData2 = fillMissingData(chartData2);

  const maxValue = Math.max(
    Math.max(...filledChartData1.map((item) => item.value)),
    Math.max(...filledChartData2.map((item) => item.value))
  );

  switch (chartType) {
    case ChartType.LINE:
      return (
        <ResponsiveContainer width="100%" height={400}>
          <LineChart data={filledChartData1}>
            <CartesianGrid strokeDasharray="3 3" />
            <XAxis dataKey="name" />
            <YAxis domain={[0, maxValue]} />
            <Tooltip />
            <Legend />
            <Line type="monotone" dataKey="value" stroke="#8884d8" activeDot={{ r: 8 }} name="Data" />
            {isComparison && (
              <Line type="monotone" data={filledChartData2} dataKey="value" stroke="#82ca9d" activeDot={{ r: 8 }} name="Comparison" />
            )}
          </LineChart>
        </ResponsiveContainer>
      );
    case ChartType.BAR:
      return (
        <ResponsiveContainer width="100%" height={400}>
          <BarChart data={filledChartData1}>
            <CartesianGrid strokeDasharray="3 3" />
            <XAxis dataKey="name" />
            <YAxis domain={[0, maxValue]} />
            <Tooltip />
            <Legend />
            <Bar dataKey="value" fill="#8884d8" name="Data" />
            {isComparison && <Bar data={filledChartData2} dataKey="value" fill="#82ca9d" name="Comparison" />}
          </BarChart>
        </ResponsiveContainer>
      );
    default:
      return <div>Invalid chart type selected. Please choose a valid chart type.</div>;
  }
};

export default DataChart;
