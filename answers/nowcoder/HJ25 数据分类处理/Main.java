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
        SortedMap<Integer, List<Integer>> matchMap = new TreeMap<>();
        for (int i = input.get(0) + 2; i < input.size(); i++) {
            matchMap.put(input.get(i), new LinkedList<>());
        }
        int count = 0;
        for (int i = 1; i <= input.get(0); i++) {
            int number = input.get(i);
            for (int rule : matchMap.keySet()) {
                if (Integer.toString(number).contains(Integer.toString(rule))) {
                    matchMap.get(rule).add(i - 1);
                    count += 2;
                }
            }
        }
        for (int rule : matchMap.keySet()) {
            if (matchMap.get(rule).size() > 0) {
                count += 2;
            }
        }
        StringBuilder sb = new StringBuilder();
        sb.append(count);
        for (int rule : matchMap.keySet()) {
            List<Integer> list = matchMap.get(rule);
            if (list.size() > 0) {
                sb.append(" ").append(rule).append(" ").append(list.size());
                for (int index : list) {
                    sb.append(" ").append(index).append(" ").append(input.get(index + 1));
                }
            }
        }

        return sb.toString();
    }
}