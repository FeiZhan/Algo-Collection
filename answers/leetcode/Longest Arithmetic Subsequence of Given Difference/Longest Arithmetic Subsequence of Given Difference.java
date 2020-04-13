class Solution {
    public int longestSubsequence(int[] arr, int difference) {
        Map<Integer, Integer> nextMap = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            int length = nextMap.getOrDefault(arr[i], 0);
            int next = arr[i] + difference;
            nextMap.put(next, length + 1);
        }
        int longest = 0;
        for (int length : nextMap.values()) {
            longest = Math.max(longest, length);
        }
        return longest;
    }
}