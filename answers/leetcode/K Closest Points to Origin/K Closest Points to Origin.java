import java.util.SortedMap;

class Solution {
    public int[][] kClosest(int[][] points, int K) {
        SortedMap<Long, List<int[]>> map = new TreeMap<>();
        for (int[] point : points) {
            long distance = (long) point[0] * point[0] + (long) point[1] * point[1];
            List<int[]> list = map.getOrDefault(distance, new LinkedList<>());
            list.add(point);
            map.put(distance, list);
        }
        List<int[]> results = new LinkedList<>();
        for (List<int[]> list : map.values()) {
            results.addAll(list);
            if (results.size() >= K) {
                break;
            }
        }
        return results.toArray(new int[results.size()][]);
    }
}