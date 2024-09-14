class Solution {
    public int minimumBoxes(int[] apple, int[] capacity) {
        int sum = 0;
        for (int number : apple) {
            sum += number;
        }

        int[] sortedCapacity = Arrays.stream(capacity).boxed().sorted(Collections.reverseOrder()).mapToInt(Integer::intValue).toArray();
        for (int i = 0; i < sortedCapacity.length; i++) {
            sum -= sortedCapacity[i];
            if (sum <= 0) {
                return i + 1;
            }
        }

        return capacity.length;
    }
}