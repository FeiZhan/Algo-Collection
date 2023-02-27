class Solution {
    public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
        int maxIndex = 0;
        Map<Integer, Integer> numberMap = new HashMap<>();
        for (int[] number : nums1) {
            maxIndex = Math.max(maxIndex, number[0]);
            numberMap.put(number[0], numberMap.getOrDefault(number[0], 0) + number[1]);
        }
        for (int[] number : nums2) {
            maxIndex = Math.max(maxIndex, number[0]);
            numberMap.put(number[0], numberMap.getOrDefault(number[0], 0) + number[1]);
        }

        int index = 0;
        int[][] result = new int[numberMap.size()][2];
        for (int i = 0; i <= maxIndex; i++) {
            if (numberMap.containsKey(i)) {
                result[index][0] = i;
                result[index][1] = numberMap.get(i);
                index++;
            }
        }

        return result;
    }
}