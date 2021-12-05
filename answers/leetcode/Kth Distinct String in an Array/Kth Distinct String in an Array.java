class Solution {
    public String kthDistinct(String[] arr, int k) {
        Map<String, Integer> strMap = new HashMap<>();
        for (String str : arr) {
            strMap.put(str, strMap.getOrDefault(str, 0) + 1);
        }

        int index = 0;
        for (String str : arr) {
            int count = strMap.get(str);
            if (count == 1) {
                index++;
                if (index == k) {
                    return str;
                }
            }
        }

        return "";
    }
}
//Runtime: 11 ms, faster than 24.75% of Java online submissions for Kth Distinct String in an Array.
//Memory Usage: 42.1 MB, less than 31.96% of Java online submissions for Kth Distinct String in an Array.
