import java.util.Scanner;

// 注意类名必须为 Main, 不要有任何 package xxx 信息
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        // 注意 hasNext 和 hasNextLine 的区别
        while (in.hasNextLine()) { // 注意 while 处理多个 case
            String a = in.nextLine();
            String b = in.nextLine();
            System.out.println(solve(a, b.charAt(0)));
        }
    }

    public static int solve(String input, char target) {
        target = Character.toLowerCase(target);
        int count = 0;
        for (char c : input.toCharArray()) {
            c = Character.toLowerCase(c);
            count += c == target ? 1 : 0;
        }

        return count;
    }
}