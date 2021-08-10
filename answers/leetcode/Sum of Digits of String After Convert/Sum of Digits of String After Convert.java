class Solution {
    public int getLucky(String s, int k) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            sb.append(String.valueOf(c - 'a' + 1));
        }

        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum = 0;
            for (char c : sb.toString().toCharArray()) {
                sum += Character.getNumericValue(c);
            }
            sb = new StringBuilder(String.valueOf(sum));
        }

        return sum;
    }
}