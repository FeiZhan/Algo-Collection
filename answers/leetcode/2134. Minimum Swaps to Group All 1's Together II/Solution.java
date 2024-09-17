class Solution {
    public int minSwaps(int[] nums) {
        int ones = 0;
        List<Integer> numberList = new ArrayList<>();
        for (int number : nums) {
            ones += number;
            numberList.add(number);
        }
        for (int number : nums) {
            numberList.add(number);
        }

        int count = 0;
        for (int i = 0; i < ones; i++) {
            count += numberList.get(i) == 0 ? 1 : 0;
        }
        int result = count;
        for (int i = ones; i < numberList.size(); i++) {
            count += (numberList.get(i) == 0 ? 1 : 0) - (numberList.get(i - ones) == 0 ? 1 : 0);
            result = Math.min(result, count);
        }

        return result;
    }
}