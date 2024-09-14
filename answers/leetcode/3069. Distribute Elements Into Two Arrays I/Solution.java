class Solution {
    public int[] resultArray(int[] nums) {
        List<Integer> array1 = new LinkedList<>();
        array1.add(nums[0]);
        List<Integer> array2 = new LinkedList<>();
        array2.add(nums[1]);
        int length = nums.length;
        for (int i = 2; i < length; i++) {
            if (array1.get(array1.size() - 1) > array2.get(array2.size() - 1)) {
                array1.add(nums[i]);
            } else {
                array2.add(nums[i]);
            }
        }

        int[] result = new int[length];
        for (int i = 0; i < length; i++) {
            result[i] = i < array1.size() ? array1.get(i) : array2.get(i - array1.size()) ;
        }

        return result;
    }
}