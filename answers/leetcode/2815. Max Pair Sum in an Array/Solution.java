class Solution {
    public int maxSum(int[] nums) {
        Map<Integer, List<Integer>> digits = new HashMap<>();
        for (int number : nums) {
            int digit = 0;
            int temp = number;
            while (temp != 0) {
                digit = Math.max(digit, temp % 10);
                temp /= 10;
            }
            List<Integer> list = digits.getOrDefault(digit, new LinkedList<>());
            list.add(number);
            digits.put(digit, list);
        }

        int max = -1;
        for (List<Integer> list : digits.values()) {
            if (list.size() < 2) {
                continue;
            }
            Collections.sort(list);
            int sum = list.get(list.size() - 2) + list.get(list.size() - 1);
            max = Math.max(max, sum);
        }

        return max;
    }
}