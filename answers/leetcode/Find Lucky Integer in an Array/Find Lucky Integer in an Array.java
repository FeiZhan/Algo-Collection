class Solution {
    public int findLucky(int[] arr) {
        Map<Integer, Integer> counts = new HashMap<>();
        for (int number : arr) {
            counts.put(number, counts.getOrDefault(number, 0) + 1);
        }
        int lucky = -1;
        for (int number : counts.keySet()) {
            if (number == counts.get(number)) {
                lucky = Math.max(lucky, number);
            }
        }
        return lucky;
    }
}