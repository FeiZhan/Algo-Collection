class Solution {
    public int maximumValue(String[] strs) {
        int max = 0;
        for (String str : strs) {
            int number = 0;
            for (char c : str.toCharArray()) {
                if (Character.isDigit(c)) {
                    number = number * 10 + Character.getNumericValue(c);
                } else {
                    number = str.length();
                    break;
                }
            }

            max = Math.max(max, number);
        }

        return max;
    }
}