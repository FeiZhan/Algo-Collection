import java.util.*;

// 注意类名必须为 Main, 不要有任何 package xxx 信息
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        List<Integer> input = new ArrayList<>();
        // 注意 hasNext 和 hasNextLine 的区别
        while (in.hasNextInt()) { // 注意 while 处理多个 case
            input.add(in.nextInt());
        }
        input.remove(0);
        System.out.println(solve(input));
    }

    public static String solve(List<Integer> input) {
        List<String> result = new LinkedList<>();
        dfs(0, new Stack<>(), "", result, input);
        Collections.sort(result);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < result.size(); i++) {
            sb.append(result.get(i));
            if (i + 1 != result.size()) {
                sb.append("\n");
            }
        }

        return sb.toString();
    }

    private static void dfs(int index, Stack<Integer> stack, String path, List<String> result, List<Integer> input) {
        if (index >= input.size() && stack.isEmpty()) {
            result.add(path);
            return;
        }

        if (!stack.isEmpty()) {
            int temp = stack.pop();
            dfs(index, stack, path + (path.length() > 0 ? " " : "") + temp, result, input);
            stack.push(temp);
        }
        if (index < input.size()) {
            stack.push(input.get(index));
            dfs(index + 1, stack, path, result, input);
            stack.pop();
        }
    }
}