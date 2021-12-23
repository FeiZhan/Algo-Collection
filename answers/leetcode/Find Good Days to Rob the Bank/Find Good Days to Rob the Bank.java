class Solution {
    public List<Integer> goodDaysToRobBank(int[] security, int time) {
        int length = security.length;
        int[] left = new int[length];
        for (int i = 1; i < length; i++) {
            if (security[i - 1] >= security[i]) {
                left[i] = left[i - 1] + 1;
            }
        }

        int[] right = new int[length];
        for (int i = length - 2; i >= 0; i--) {
            if (security[i] <= security[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }

        List<Integer> result = new LinkedList<>();
        for (int i = 0; i < length; i++) {
            if (left[i] >= time && right[i] >= time) {
                result.add(i);
            }
        }

        return result;
    }
}
//Runtime: 7 ms, faster than 78.12% of Java online submissions for Find Good Days to Rob the Bank.
//Memory Usage: 61.5 MB, less than 45.92% of Java online submissions for Find Good Days to Rob the Bank.
