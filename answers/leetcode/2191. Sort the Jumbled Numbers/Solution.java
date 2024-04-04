class Solution {
    public int[] sortJumbled(int[] mapping, int[] nums) {
        SortedMap<Integer, List<Integer>> sorted = new TreeMap<>();
        for (int number : nums) {
            int temp = number;
            List<Integer> digits = new LinkedList<>();
            if (number == 0) {
                digits.add(mapping[0]);
            }
            while (temp > 0) {
                digits.add(0, mapping[temp % 10]);
                temp /= 10;
            }

            int mappedNumber = 0;
            for (int digit : digits) {
                mappedNumber = mappedNumber * 10 + digit;
            }

            List<Integer> list = sorted.getOrDefault(mappedNumber, new LinkedList<>());
            list.add(number);
            sorted.put(mappedNumber, list);
        }

        int index = 0;
        int[] result = new int[nums.length];
        for (List<Integer> list : sorted.values()) {
            for (int number : list) {
                result[index] = number;
                index++;
            }
        }

        return result;
    }
}