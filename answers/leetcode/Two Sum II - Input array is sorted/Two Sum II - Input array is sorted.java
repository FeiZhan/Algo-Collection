class Solution {
    public int[] twoSum(int[] numbers, int target) {
        for (int i = 0; i < numbers.length; i++) {
            int remain = target - numbers[i];
            int left = 0;
            int right = numbers.length - 1;
            if (remain < numbers[i]) {
                right = i - 1;
            } else {
                left = i + 1;
            }
            while (left <= right) {
                int middle = (left + right) / 2;
                if (numbers[middle] == remain) {
                    int[] result = new int[2];
                    result[0] = Math.min(i, middle) + 1;
                    result[1] = Math.max(i, middle) + 1;
                    return result;
                } else if (numbers[middle] < remain) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }
        }
        return new int[2];
    }
}