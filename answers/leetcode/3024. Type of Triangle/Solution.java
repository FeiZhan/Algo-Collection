class Solution {
    public String triangleType(int[] nums) {
        final String[] TRIANGLE_TYPES = new String[]{"equilateral", "isosceles", "scalene"};
        Arrays.sort(nums);
        if (nums[0] + nums[1] <= nums[2]) {
            return "none";
        }
        
        Set<Integer> numbers = new HashSet<>();
        for (int number : nums) {
            numbers.add(number);
        }

        return TRIANGLE_TYPES[numbers.size() - 1];
    }
}