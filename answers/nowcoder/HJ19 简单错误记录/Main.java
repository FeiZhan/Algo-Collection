import java.util.*;

// 注意类名必须为 Main, 不要有任何 package xxx 信息
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        List<String> input = new LinkedList<>();
        // 注意 hasNext 和 hasNextLine 的区别
        while (in.hasNextLine()) { // 注意 while 处理多个 case
            input.add(in.nextLine());
        }
        System.out.println(solve(input));
    }

    public static String solve(List<String> input) {
        List<String> errors = new LinkedList<>();
        Map<String, Integer> errorMap = new HashMap<>();
        for (String line : input) {
            String[] split = line.split(" ");
            String[] path = split[0].split("\\\\");
            String name = path[path.length - 1];
            name = name.substring(Math.max(name.length() - 16, 0));
            String error = name + " " + split[1];
            if (!errorMap.containsKey(error)) {
                errorMap.put(error, 0);
                errors.add(error);
            }
            errorMap.put(error, errorMap.get(error) + 1);
        }
        StringBuilder sb = new StringBuilder();
        for (int i = Math.max(errors.size() - 8, 0); i < errors.size(); i++) {
            String error = errors.get(i);
            sb.append(error).append(" ").append(errorMap.get(error));
            if (i + 1 < errors.size()) {
                sb.append("\n");
            }
        }
        return sb.toString();
    }
}