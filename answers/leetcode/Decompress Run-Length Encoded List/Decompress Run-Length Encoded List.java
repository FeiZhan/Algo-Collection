class Solution {
    public int[] decompressRLElist(int[] nums) {
        List<Integer> decompressed = new LinkedList<>();
        for (int i = 1; i < nums.length; i += 2) {
            for (int j = 0; j < nums[i - 1]; j++) {
                decompressed.add(nums[i]);
            }
        }
        int[] result = new int[decompressed.size()];
        for (int i = 0; i < decompressed.size(); i++) {
            result[i] = decompressed.get(i);
        }
        return result;
    }
}