import java.util.*;

// 注意类名必须为 Main, 不要有任何 package xxx 信息
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        // 注意 hasNext 和 hasNextLine 的区别
        while (in.hasNextLine()) { // 注意 while 处理多个 case
            String a = in.nextLine();
            System.out.println(solve(a));
        }
    }

    public static String solve(String input) {
        boolean valid = false;
        if (input != null && input.length() >= 8) {
            boolean[] flags = new boolean[4];
            for (char c : input.toCharArray()) {
                if (Character.isUpperCase(c)) {
                    flags[0] = true;
                } else if (Character.isLowerCase(c)) {
                    flags[1] = true;
                } else if (Character.isDigit(c)) {
                    flags[2] = true;
                } else {
                    flags[3] = true;
                }
            }
            int count = 0;
            for (boolean flag : flags) {
                count += flag ? 1 : 0;
            }
            if (count >= 3) {
                valid = true;
                for (int i = 2; i < input.length(); i++) {
                    if (input.substring(i + 1).contains(input.substring(i - 2, i + 1))) {
                        valid = false;
                        break;
                    }
                }
            }
        }

        return valid ? "OK" : "NG";
    }
}