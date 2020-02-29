class Solution {
    public int findSpecialInteger(int[] arr) {
        Map<Integer, Integer> counts = new HashMap<>();
        for (int number : arr) {
            counts.put(number, counts.getOrDefault(number, 0) + 1);
        }
        for (int number : counts.keySet()) {
            if (counts.get(number) * 4 > arr.length) {
                return number;
            }
        }
        return -1;
    }
}