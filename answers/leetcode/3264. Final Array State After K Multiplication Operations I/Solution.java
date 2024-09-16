class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        Map<Integer, SortedSet<Integer>> numberMap = new HashMap<>();
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        for (int i = 0; i < nums.length; i++) {
            SortedSet<Integer> set = numberMap.getOrDefault(nums[i], new TreeSet<>());
            set.add(i);
            numberMap.put(nums[i], set);
            queue.add(nums[i]);
        }
        while (k-- > 0) {
            int number = queue.poll();
            SortedSet<Integer> set = numberMap.get(number);
            int index = set.removeFirst();
            number *= multiplier;
            set = numberMap.getOrDefault(number, new TreeSet<>());
            set.add(index);
            numberMap.put(number, set);
            queue.add(number);
        }
        int[] result = new int[nums.length];
        for (int number : numberMap.keySet()) {
            SortedSet<Integer> set = numberMap.get(number);
            for (int index : set) {
                result[index] = number;
            }
        }

        return result;
    }
}