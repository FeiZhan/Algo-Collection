import java.util.SortedSet;

class Solution {

    private static SortedSet<Integer> fibonacci = new TreeSet<>();

    static {
        int number = 1;
        int previous = 1;
        while (number > 0) {
            fibonacci.add(number);
            int temp = number;
            number += previous;
            previous = temp;
        }
    }

    public int findMinFibonacciNumbers(int k) {
        int count = 0;
        while (k > 0) {
            SortedSet<Integer> headSet = fibonacci.headSet(k + 1);
            if (headSet.isEmpty()) {
                break;
            }
            int last = headSet.last();
            k -= last;
            count++;
        }
        return count;
    }
}