import java.util.Scanner;

// 注意类名必须为 Main, 不要有任何 package xxx 信息
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        // 注意 hasNext 和 hasNextLine 的区别
        while (in.hasNextLine()) { // 注意 while 处理多个 case
            String input = in.nextLine();
            System.out.println(solve(input));
        }
    }

    public static int solve(String input) {
        int left = -1;
        int size = 0;
        for (int i = 0; i < input.length(); i++) {
            char c = input.charAt(i);
            if (Character.isAlphabetic(c)) {
                if (left == -1) {
                    left = i;
                }
                size = i - left + 1;
            } else if (left != -1) {
                left = -1;
            }
        }

        return size;
    }
}