class Solution {
    public boolean canChoose(int[][] groups, int[] nums) {
        int groupIndex = 0;
        int groupLength = groups[groupIndex].length;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == groups[groupIndex][0] && i + groupLength <= nums.length) {
                boolean flag = true;
                for (int j = 0; j < groupLength; j++) {
                    if (groups[groupIndex][j] != nums[i + j]) {
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    i += groupLength - 1;
                    groupIndex++;
                    if (groupIndex >= groups.length) {
                        return true;
                    }
                    groupLength = groups[groupIndex].length;
                }
            }
        }

        return false;
    }
}