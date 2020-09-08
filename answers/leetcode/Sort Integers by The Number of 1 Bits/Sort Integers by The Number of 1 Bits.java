import java.util.SortedMap;

class Solution {
    public int[] sortByBits(int[] arr) {
        SortedMap<Integer, List<Integer>> bits = new TreeMap<>();
        for (int number : arr) {
            int count = Integer.bitCount(number);
            List<Integer> list = bits.getOrDefault(count, new ArrayList<>());
            list.add(number);
            bits.put(count, list);
        }
        int index = 0;
        int[] result = new int[arr.length];
        for (List<Integer> list : bits.values()) {
            Collections.sort(list);
            for (int number : list) {
                result[index] = number;
                index++;
            }
        }
        return result;
    }
}