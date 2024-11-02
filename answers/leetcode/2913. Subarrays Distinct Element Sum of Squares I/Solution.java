class Solution {
    public int sumCounts(List<Integer> nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            Set<Integer> numberSet = new HashSet<>();
            for (int j = i; j < nums.size(); j++) {
                numberSet.add(nums.get(j));
                result += numberSet.size() * numberSet.size();
            }
        }

        return result;
    }
}