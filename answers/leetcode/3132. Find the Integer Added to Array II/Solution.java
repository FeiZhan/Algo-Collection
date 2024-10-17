class Solution {
    public int minimumAddedInteger(int[] nums1, int[] nums2) {
        Map<Integer, Integer> numberMap = new HashMap<>();
        for (int number : nums1) {
            numberMap.put(number, numberMap.getOrDefault(number, 0) + 1);
        }
        int min2 = Integer.MAX_VALUE;
        for (int number : nums2) {
            min2 = Math.min(min2, number);
        }
        int result = Integer.MAX_VALUE;
        for (int i = 0; i < nums1.length; i++) {
            int diff = min2 - nums1[i];
            if (diff >= result) {
                continue;
            }
            boolean flag = true;
            Map<Integer, Integer> map = new HashMap<>(numberMap);
            for (int number : nums2) {
                number -= diff;
                if (map.containsKey(number)) {
                    map.put(number, map.get(number) - 1);
                    if (map.get(number) == 0) {
                        map.remove(number);
                    }
                } else {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                result = diff;
            }
        }

        return result;
    }
}