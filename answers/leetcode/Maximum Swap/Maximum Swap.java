class Solution {
    public int maximumSwap(int num) {
        Stack<Integer> stack = new Stack<>();
        String number = Integer.toString(num);
        for (int i = 0; i < number.length(); i++) {
            int digit = Character.getNumericValue(number.charAt(i));
            if (stack.isEmpty()) {
                stack.push(i);
            } else {
                int previous = Character.getNumericValue(number.charAt(stack.peek()));
                if (previous > digit) {
                    stack.push(i);
                } else if (previous < digit) {
                    int right = i;
                    for (int j = i; j < number.length(); j++) {
                        if (Character.getNumericValue(number.charAt(j)) >= Character.getNumericValue(number.charAt(right))) {
                            right = j;
                        }
                    }
                    digit = Character.getNumericValue(number.charAt(right));
                    int left = 0;
                    while (!stack.isEmpty() && previous < digit) {
                        left = stack.pop();
                        if (!stack.isEmpty()) {
                            previous = Character.getNumericValue(number.charAt(stack.peek()));
                        }
                    }
                    StringBuilder swapped = new StringBuilder();
                    swapped.append(number.substring(0, left))
                        .append(digit)
                        .append(number.substring(left + 1, right))
                        .append(number.charAt(left))
                        .append(number.substring(right + 1));
                    return Integer.parseInt(swapped.toString());
                }
            }
        }
        return num;
    }
}