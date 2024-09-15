class Solution {
    public int generateKey(int num1, int num2, int num3) {
        List<Integer> numbers = new LinkedList<>();
        numbers.add(num1);
        numbers.add(num2);
        numbers.add(num3);
        boolean flag = true;
        int tens = 1;
        int result = 0;
        while (flag) {
            flag = false;
            int minDigit = 10;
            for (int i = 0; i < numbers.size(); i++) {
                int number = numbers.get(i);
                minDigit = Math.min(minDigit, number % 10);
                numbers.set(i, number / 10);
                if (numbers.get(i) > 0) {
                    flag = true;
                }
            }
            result += tens * minDigit;
            tens *= 10;
        }

        return result;
    }
}