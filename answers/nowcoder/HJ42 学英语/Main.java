import java.util.*;

// 注意类名必须为 Main, 不要有任何 package xxx 信息
public class Main {
    private static final List<String> NUMBERS = new ArrayList<>();
    private static final List<String> TENS = new ArrayList<>();

    static {
        NUMBERS.add("zero");
        NUMBERS.add("one");
        NUMBERS.add("two");
        NUMBERS.add("three");
        NUMBERS.add("four");
        NUMBERS.add("five");
        NUMBERS.add("six");
        NUMBERS.add("seven");
        NUMBERS.add("eight");
        NUMBERS.add("nine");
        NUMBERS.add("ten");
        NUMBERS.add("eleven");
        NUMBERS.add("twelve");
        NUMBERS.add("thirteen");
        NUMBERS.add("fourteen");
        NUMBERS.add("fifteen");
        NUMBERS.add("sixteen");
        NUMBERS.add("seventeen");
        NUMBERS.add("eighteen");
        NUMBERS.add("nineteen");
        TENS.add("zero");
        TENS.add("ten");
        TENS.add("twenty");
        TENS.add("thirty");
        TENS.add("forty");
        TENS.add("fifty");
        TENS.add("sixty");
        TENS.add("seventy");
        TENS.add("eighty");
        TENS.add("ninety");
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        // 注意 hasNext 和 hasNextLine 的区别
        while (in.hasNextInt()) { // 注意 while 处理多个 case
            int a = in.nextInt();
            System.out.println(solve(a));
        }
    }

    public static String solve(int number) {
        StringBuilder sb = new StringBuilder();
        if (number == 0) {
            sb.append(NUMBERS.get(number));
        } else {
            if (number % 1000 > 0) {
                sb.append(solve3(number % 1000));
            }
            number /= 1000;
            if (number % 1000 > 0) {
                sb.insert(0, " thousand ").insert(0, solve3(number % 1000));
            }
            number /= 1000;
            if (number % 1000 > 0) {
                sb.insert(0, " million ").insert(0, solve3(number % 1000));
            }
            number /= 1000;
            if (number % 1000 > 0) {
                sb.insert(0, " billion ").insert(0, solve3(number % 1000));
            }
            number /= 1000;
        }

        return sb.toString();
    }

    private static String solve3(int number) {
        StringBuilder sb = new StringBuilder();
        if (number % 100 > 0 && number % 100 < 20) {
            sb.append(NUMBERS.get(number % 100));
            number /= 100;
        } else {
            if (number % 10 > 0) {
                sb.append(NUMBERS.get(number % 10));
            }
            number /= 10;
            if (number % 10 > 0) {
                sb.insert(0, (sb.length() > 0 ? " " : "")).insert(0, TENS.get(number % 10));
            }
            number /= 10;
        }
        if (number % 10 > 0) {
            sb.insert(0, (sb.length() > 0 ? "and " : "")).insert(0, " hundred ").insert(0, NUMBERS.get(number % 10));
        }

        return sb.toString();
    }
}