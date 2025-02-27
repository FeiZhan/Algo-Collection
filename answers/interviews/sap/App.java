import java.util.*;

public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");
        // null
        System.out.println(parseIP(null));
        // ""
        System.out.println(parseIP(""));
        // "a"
        System.out.println(parseIP("a"));
        // "1"
        System.out.println(parseIP("1"));
        // "0.0.0"
        System.out.println(parseIP("0.0.0"));
        // "0.0.0.0"
        System.out.println(parseIP("0.0.0.0"));
        // "0.-1.0.0"
        System.out.println(parseIP("0.-1.0.0"));
        // "0.256.0.0"
        System.out.println(parseIP("0.256.0.0"));
        // "0.0.0.0.0"
        System.out.println(parseIP("0.0.0.0.0"));
    }

    public static boolean parseIP(String raw) {
        if (raw == null) {
            return false;
        }

        String[] split = raw.split("\\.");
        if (split.length != 4) {
            return false;
        }
        for (String part : split) {
            try {
                int number = Integer.parseInt(part);
                if (number < 0 || number > 255) {
                    return false;
                }
            } catch (Exception e) {
                return false;
            }
        }
        return true;
    }

    // [6 7 8 0 1 2 3 4 5], 3
    // left = 0 (6), right = 8 (5), middle = 4 (1), middle number > target && target > right number, move left
    // left = 5 (2), right = 8 (5), middle = 6 (3), found
    public static int search(List<Integer> input, int target) {
        int left = 0;
        int right = input.size() - 1;
        while (left <= right) {
            int rightNumber = input.get(right);
            int middle = (left + right) / 2;
            int number = input.get(middle);
            if (number == target) {
                return number;
            }
            if (number < target) {
                if (target <= rightNumber) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            } else if (number > target) {
                if (target <= rightNumber) {
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
            }
        }
        return -1;
    }
}
