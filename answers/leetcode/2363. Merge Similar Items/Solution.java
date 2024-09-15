import java.util.SortedMap;

class Solution {
    public List<List<Integer>> mergeSimilarItems(int[][] items1, int[][] items2) {
        SortedMap<Integer, Integer> map = new TreeMap<>();
        for (int[] item : items1) {
            map.put(item[0], item[1]);
        }
        for (int[] item : items2) {
            map.put(item[0], map.getOrDefault(item[0], 0) + item[1]);
        }
        List<List<Integer>> result = new LinkedList<>();
        for (int key : map.keySet()) {
            List<Integer> list = new LinkedList<>();
            list.add(key);
            list.add(map.get(key));
            result.add(list);
        }

        return result;
    }
}