class Solution {
    public int minimumRightShifts(List<Integer> nums) {
        int size = nums.size();
        if (nums == null || size <= 1) {
            return 0;
        }

        int head = nums.get(0);
        int tail = nums.get(size - 1);
        if (head < tail) {
            for (int i = 1; i < size; i++) {
                if (nums.get(i - 1) >= nums.get(i)) {
                    return -1;
                }
            }
            return 0;
        } else {
            int index = -1;
            for (int i = 1; i < size; i++) {
                if (nums.get(i - 1) >= nums.get(i)) {
                    if (index < 0) {
                        index = i;
                    } else {
                        return -1;
                    }
                }
            }
            return size - index;
        }
    }
}