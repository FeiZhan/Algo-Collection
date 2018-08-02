class Solution {
    public int calculate(String s) {
        Stack<Integer> numbers = new Stack<>();
        char previous = '+';
        int num = 0;
        for (int i = 0; i <= s.length(); i++) {
            if (i < s.length() && Character.isDigit(s.charAt(i))) {
                num = num * 10 + Character.getNumericValue(s.charAt(i));
            } else if (i == s.length() || s.charAt(i) != ' ') {
                switch (previous) {
                    case '+':
                        numbers.push(num);
                        break;
                    case '-':
                        numbers.push(- num);
                        break;
                    case '*':
                        numbers.push(numbers.pop() * num);
                        break;
                    case '/':
                        numbers.push(numbers.pop() / num);
                        break;
                }
                if (i < s.length()) {
                    previous = s.charAt(i);
                    num = 0;
                }
            }
        }
        num = 0;
        while (!numbers.isEmpty()) {
            num += numbers.pop();
        }
        return num;
    }
}