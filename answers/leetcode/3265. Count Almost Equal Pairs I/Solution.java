class Solution {
    public int countPairs(int[] nums) {
        int result = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                int number0 = nums[i];
                int number1 = nums[j];
                List<Integer> digits0 = new LinkedList<>();
                List<Integer> digits1 = new LinkedList<>();
                while (number0 > 0 || number1 > 0) {
                    int digit0 = number0 % 10;
                    int digit1 = number1 % 10;
                    if (digit0 != digit1) {
                        digits0.add(digit0);
                        digits1.add(digit1);
                        if (digits0.size() > 2) {
                            break;
                        }
                    }
                    number0 /= 10;
                    number1 /= 10;
                }
                if (digits0.size() == 0 || digits0.size() == 2) {
                    Collections.sort(digits0);
                    Collections.sort(digits1);
                    boolean flag = true;
                    for (int k = 0; k < digits0.size(); k++) {
                        if (digits0.get(k) != digits1.get(k)) {
                            flag = false;
                            break;
                        }
                    }
                    result += flag ? 1 : 0;
                }
            }
        }

        return result;
    }
}