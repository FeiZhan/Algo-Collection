import java.util.Scanner;

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
        int x = 0;
        int y = 0;
        String[] split = input.split(";");
        for (String move : split) {
            if (move.length() >= 2) {
                char direction = move.charAt(0);
                try {
                    int length = Integer.parseInt(move.substring(1));
                    if (length >= 1 && length <= 99) {
                        switch (direction) {
                            case 'A':
                                x -= length;
                                break;
                            case 'D':
                                x += length;
                                break;
                            case 'W':
                                y += length;
                                break;
                            case 'S':
                                y -= length;
                                break;
                        }
                    }
                } catch (Exception e) {
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        sb.append(x).append(",").append(y);

        return sb.toString();
    }
}