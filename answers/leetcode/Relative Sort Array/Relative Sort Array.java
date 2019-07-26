import java.util.SortedMap;

/*
 * @lc app=leetcode id=1122 lang=java
 *
 * [1122] Relative Sort Array
 */
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        SortedMap<Integer, Integer> counts = new TreeMap<>();
        for (int number : arr1) {
            counts.put(number, counts.getOrDefault(number, 0) + 1);
        }
        int index = 0;
        for (int number : arr2) {
            int count = counts.get(number);
            for (int i = 0; i < count; i++) {
                arr1[index + i] = number;
            }
            index += count;
            counts.remove(number);
        }
        for (int number : counts.keySet()) {
            int count = counts.get(number);
            for (int i = 0; i < count; i++) {
                arr1[index + i] = number;
            }
            index += count;
        }
        return arr1;
    }
}

