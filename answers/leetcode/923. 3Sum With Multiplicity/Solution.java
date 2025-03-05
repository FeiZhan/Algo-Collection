class Solution {
    public int threeSumMulti(int[] arr, int target) {
        Map<Integer, Long> numberMap = new HashMap<>();
        for (int number : arr) {
            numberMap.put(number, numberMap.getOrDefault(number, 0l) + 1l);
        }
        long result = 0l;
        List<Integer> numbers = new ArrayList<>(numberMap.keySet());
        Collections.sort(numbers);
        for (int i = 0; i < numbers.size(); i++) {
            int number0 = numbers.get(i);
            long count0 = numberMap.get(number0);
            if (count0 >= 2) {
                int number2 = target - number0 - number0;
                if (numberMap.containsKey(number2)) {
                    if (number2 == number0 & count0 >= 3) {
                        result += count0 * (count0 - 1) * (count0 - 2) / 6;
                    } else if (number2 > number0) {
                        result += count0 * (count0 - 1) / 2 * numberMap.get(number2);
                    }
                }
            }
            for (int j = i + 1; j < numbers.size(); j++) {
                int number1 = numbers.get(j);
                long count1 = numberMap.get(number1);
                int number2 = target - number0 - number1;
                if (numberMap.containsKey(number2)) {
                    if (number2 == number1 && count1 >= 2) {
                        result += count0 * count1 * (count1 - 1) / 2;
                    } else if (number2 > number1) {
                        result += count0 * count1 * numberMap.get(number2);
                    }
                }
            }
        }
        return (int)(result % (1e9 + 7));
    }
}