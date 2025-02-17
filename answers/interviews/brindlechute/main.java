// Online Java Compiler
// Use this editor to write, compile and run your Java code online
import java.util.*;

class Main {
    public static void main(String[] args) {
        getFriendPair(3000);
    }

    // sum(n / i) O(n log n)
    public static void getFriendPair(int n) {
        int[] sums = new int[n + 1];
        // O(n)
        for (int i = 1; i <= n; i++) {
            // O()
            for (int j = 2; i * j <= n; j++) {
                sums[i * j] += i;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (sums[i] < i && sums[sums[i]] == i) {
                System.out.println(i + " " + sums[i]);
            }
        }
    }

    private static int getDivisionSum(int number) {
        int sum = 0;
        // O(number ^ 1/2)
        for (int i = 1; i < number; i++) {
            if (number % i == 0) {
                sum += i;
            }
        }
        return sum;
    }


}