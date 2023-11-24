class Solution {
    public String optimalDivision(int[] nums) {
        StringBuilder sb = new StringBuilder();
        if (nums.length >= 1) {
            sb.append(nums[0]);
            if (nums.length >= 2) {
                sb.append('/');
                if (nums.length == 2) {
                    sb.append(nums[1]);
                } else {
                    sb.append('(');
                    for (int i = 1; i < nums.length; i++) {
                        sb.append(nums[i]);
                        if (i + 1 != nums.length) {
                            sb.append('/');
                        }
                    }
                    sb.append(')');
                }
            }
        }

        return sb.toString();
    }
}