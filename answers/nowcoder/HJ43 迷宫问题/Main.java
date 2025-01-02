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
        System.out.println(solve(input));
    }

    public static String solve(List<Integer> input) {
        int height = input.get(0);
        int width = input.get(1);
        List<List<Integer>> map = new ArrayList<>();
        for (int i = 0; i < height; i++) {
            List<Integer> row = new ArrayList<>();
            for (int j = 0; j < width; j++) {
                row.add(input.get(i * width + j + 2));
            }
            map.add(row);
        }

        List<List<Integer>> path = new LinkedList<>();
        StringBuilder sb = new StringBuilder();
        if (dfs(0, 0, path, map)) {
            for (List<Integer> coordinate : path) {
                sb.append("(").append(coordinate.get(0)).append(",").append(coordinate.get(1)).append(")\n");
            }
        }

        return sb.toString();
    }

    private static boolean dfs(int x, int y, List<List<Integer>> path, List<List<Integer>> map) {
        if (x < 0 || x >= map.size() || y < 0 || y >= map.get(0).size() || map.get(x).get(y) != 0) {
            return false;
        } else if (x + 1 == map.size() && y + 1 == map.get(x).size()) {
            List<Integer> coordinate = new ArrayList<>();
            coordinate.add(x);
            coordinate.add(y);
            path.add(coordinate);
            return true;
        }

        map.get(x).set(y, 2);
        List<Integer> coordinate = new ArrayList<>();
        coordinate.add(x);
        coordinate.add(y);
        path.add(coordinate);
        if (dfs(x - 1, y, path, map) || dfs(x + 1, y, path, map) || dfs(x, y - 1, path, map) || dfs(x, y + 1, path, map)) {
            return true;
        }
        map.get(x).set(y, 0);
        path.remove(path.size() - 1);
        return false;
    }
}