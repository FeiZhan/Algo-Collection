class Solution {
    public String minimizeResult(String expression) {
        boolean flag = false;
        List<Integer> leftDigits = new ArrayList<>();
        List<Integer> rightDigits = new ArrayList<>();

        for (char c : expression.toCharArray()) {
            if (c == '+') {
                flag = true;
            } else {
                int digit = Character.getNumericValue(c);
                if (flag) {
                    rightDigits.add(digit);
                } else {
                    leftDigits.add(digit);
                }
            }
        }

        int leftNumber = 0;
        int minResult = Integer.MAX_VALUE;
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < leftDigits.size(); i++) {
            int number1 = 0;
            for (int j = i; j < leftDigits.size(); j++) {
                number1 = number1 * 10 + leftDigits.get(j);
            }

            int number2 = 0;
            for (int j = 0; j < rightDigits.size(); j++) {
                number2 = number2 * 10 + rightDigits.get(j);
                int rightNumber = 0;
                for (int k = j + 1; k < rightDigits.size(); k++) {
                    rightNumber = rightNumber * 10 + rightDigits.get(k);
                }

                int result = Math.max(leftNumber, 1)
                    * (number1 + number2)
                    * Math.max(rightNumber, 1);
                if (result < minResult) {
                    minResult = result;
                    sb = new StringBuilder();
                    if (leftNumber > 0) {
                        sb.append(leftNumber);
                    }
                    sb
                        .append('(')
                        .append(number1)
                        .append('+')
                        .append(number2)
                        .append(')');
                    if (rightNumber > 0) {
                        sb.append(rightNumber);
                    }
                }
            }

            leftNumber = leftNumber * 10 + leftDigits.get(i);
        }

        return sb.toString();
    }
}
//Runtime: 2 ms, faster than 91.63% of Java online submissions for Minimize Result by Adding Parentheses to Expression.
//Memory Usage: 42.1 MB, less than 79.48% of Java online submissions for Minimize Result by Adding Parentheses to Expression.
