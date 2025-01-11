import java.util.*;

// 注意类名必须为 Main, 不要有任何 package xxx 信息
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        // 注意 hasNext 和 hasNextLine 的区别
        while (in.hasNextLine()) { // 注意 while 处理多个 case
            System.out.println(solve(in.nextLine()));
        }
    }

    public static String solve(String input) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < input.length(); i += 8) {
            if (i + 8 < input.length()) {
                sb.append(input.substring(i, i + 8));
            } else {
                sb.append(input.substring(i));
                for (int j = input.length() - i; j < 8; j++) {
                    sb.append('0');
                }
            }
            if (i + 1 < input.length()) {
                sb.append("\n");
            }
        }

        return sb.toString();
    }
}