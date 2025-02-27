/*public class MySingleton {
    private static A instance = null;

    private MySingleton() {}

    public static A getInstance() {
        if (instance == null) {
            instance = new A();
        }
        return instance;
    }
}*/

import java.util.*;

public class Main {
    public static void main(String[] arg) {
        for (int i = 1; i < 100; i++) {
            System.out.println(i + " " + getSquare(i));
        }
    }

    public static boolean getSquare(int number) {
        Set<Integer> visited = new HashSet<>();
        while (number != 1 && !visited.contains(number)) {
            visited.add(number);
            int sum = 0;
            while (number > 0) {
                int digit = number % 10;
                sum += digit * digit;
                number /= 10;
            }
            number = sum;
        }
        return number == 1;
    }
}
