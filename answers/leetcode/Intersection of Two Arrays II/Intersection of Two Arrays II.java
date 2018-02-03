class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        Map<Integer, Integer> numMap = new HashMap<Integer, Integer>();
        for (int num : nums1) {
            numMap.put(num, numMap.containsKey(num) ? numMap.get(num) + 1 : 1);
        }
        List<Integer> numList = new ArrayList<Integer>();
        for (int num : nums2) {
            if (numMap.containsKey(num) && numMap.get(num) > 0) {
                numList.add(num);
                numMap.put(num, numMap.get(num) - 1);
            }
        }
        int[] result = new int[numList.size()];
        for (int i = 0; i < numList.size(); i++) {
            result[i] = numList.get(i);
        }
        return result;
    }
}