import java.util.SortedMap;

class Solution {
    public int maximumPopulation(int[][] logs) {
        SortedMap<Integer, Integer> map = new TreeMap<>();
        for (int[] log : logs) {
            map.put(log[0], map.getOrDefault(log[0], 0) + 1);
            map.put(log[1], map.getOrDefault(log[1], 0) - 1);
        }

        int current = 0;
        int max = 0;
        int result = 0;
        for (int year : map.keySet()) {
            current += map.get(year);
            if (current > max) {
                max = current;
                result = year;
            }
        }

        return result;
    }
}