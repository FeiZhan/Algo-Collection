class Solution {
    public void wiggleSort(int[] nums) {
        int length = nums.length;
        int median = this.findKthLargest((length + 1) / 2, nums);
        int left = 0;
        int right = length - 1;
        for (int i = 0; i <= right; i++) {
            if (nums[this.newIndex(i, length)] > median) {
                this.swap(this.newIndex(left, length), this.newIndex(i, length), nums);
                left++;
            } else if (nums[this.newIndex(i, length)] < median) {
                this.swap(this.newIndex(right, length), this.newIndex(i, length), nums);
                right--;
                i--;
            }
        }
    }

    private int findKthLargest(int k, int[] nums) {
        return findKthLargest(k, nums, 0, nums.length - 1);
    }

    private int findKthLargest(int k, int[] nums, int start, int end) {
        int left = start;
        int right = end;
        int pivot = nums[end];
        while (left < right) {
            if (nums[left] < pivot) {
                left++;
            } else {
                right--;
                this.swap(left, right, nums);
            }
        }
        this.swap(left, end, nums);
        if (left - start + 1 == k) {
            return nums[left];
        } else if (left - start + 1 < k) {
            return this.findKthLargest(k - left + start - 1, nums, left + 1, end);
        } else {
            return this.findKthLargest(k, nums, start, left - 1);
        }
    }

    private int newIndex(int index, int length) {
        return (2 * index  + 1) % (length | 1);
    }

    private void swap(int index1, int index2, int[] nums) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
}