import java.util.SortedSet;

class Solution {
    public long[] unmarkedSumArray(int[] nums, int[][] queries) {
        long sum = 0l;
        Map<Integer, SortedSet<Integer>> indexMap = new HashMap<>();
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        for (int i = 0; i < nums.length; i++) {
            int number = nums[i];
            sum += number;
            SortedSet<Integer> indexes = indexMap.getOrDefault(number, new TreeSet<>());
            indexes.add(i);
            indexMap.put(number, indexes);
            queue.add(number);
        }

        Set<Integer> marked = new HashSet<>();
        long[] result = new long[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int[] query = queries[i];
            if (!marked.contains(query[0])) {
                marked.add(query[0]);
                int number = nums[query[0]];
                sum -= number;
                indexMap.get(number).remove(query[0]);
                queue.remove(number);
            }

            for (int j = 0; j < query[1]; j++) {
                if (queue.isEmpty()) {
                    break;
                }
                int number = queue.poll();
                int index = indexMap.get(number).iterator().next();
                marked.add(index);
                sum -= number;
                indexMap.get(number).remove(index);
            }
            result[i] = sum;
        }

        return result;
    }
}