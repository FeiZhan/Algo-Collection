import java.util.SortedMap;

/*
 * @lc app=leetcode id=1090 lang=java
 *
 * [1090] Largest Values From Labels
 */
class Solution {
    public int largestValsFromLabels(int[] values, int[] labels, int num_wanted, int use_limit) {
        Map<Integer, SortedMap<Integer, Integer>> valueMap = new HashMap<>();
        for (int i = 0; i < values.length; i++) {
            SortedMap<Integer, Integer> temp = valueMap.getOrDefault(labels[i], new TreeMap<>());
            temp.put(values[i], temp.getOrDefault(values[i], 0) + 1);
            valueMap.put(labels[i], temp);
        }
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        for (SortedMap<Integer, Integer> temp : valueMap.values()) {
            for (int i = 0; i < use_limit && !temp.isEmpty(); i++) {
                int value = temp.lastKey();
                temp.put(value, temp.get(value) - 1);
                if (temp.get(value) == 0) {
                    temp.remove(value);
                }
                queue.add(value);
                if (queue.size() > num_wanted) {
                    queue.poll();
                }
            }
        }
        int sum = 0;
        for (int value : queue) {
            sum += value;
        }
        return sum;
    }
}

