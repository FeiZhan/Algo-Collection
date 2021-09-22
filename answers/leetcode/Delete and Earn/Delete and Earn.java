import java.util.SortedMap;

class Solution {
    public int deleteAndEarn(int[] nums) {
        SortedMap<Integer, Integer> numberCounts = new TreeMap<>();
        for (int number : nums) {
            numberCounts.put(number, numberCounts.getOrDefault(number, 0) + 1);
        }

        int length = numberCounts.size();
        List<Integer> numbers = new LinkedList<>(numberCounts.keySet());
        int[] takeDp = new int[length];
        takeDp[0] = numbers.get(0) * numberCounts.get(numbers.get(0));
        int[] skipDp = new int[length];
        int result = takeDp[0];

        for (int i = 1; i < length; i++) {
            int number = numbers.get(i);
            skipDp[i] = Math.max(takeDp[i - 1], skipDp[i - 1]);
            if (number == numbers.get(i - 1) + 1) {
                takeDp[i] = Math.max((i >= 2 ? takeDp[i - 2] : 0), skipDp[i - 1]) + number * numberCounts.get(number);
            } else {
                takeDp[i] = Math.max(takeDp[i - 1], skipDp[i - 1]) + number * numberCounts.get(number);
            }
            result = Math.max(result, Math.max(takeDp[i], skipDp[i]));
            //System.out.println(takeDp[i] + " " + skipDp[i] + " " + result);
        }

        return result;
    }
}