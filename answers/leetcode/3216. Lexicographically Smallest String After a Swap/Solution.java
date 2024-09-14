class Solution {
    public String getSmallestString(String s) {
        boolean flag = false;
        int previous = Character.getNumericValue(s.charAt(0));
        StringBuilder sb = new StringBuilder();

        for (int i = 1; i < s.length(); i++) {
            int digit = Character.getNumericValue(s.charAt(i));
            if (!flag && previous % 2 == digit % 2 && previous > digit) {
                sb.append(digit);
                flag = true;
            } else {
                sb.append(previous);
                previous = digit;
            }
        }
        sb.append(previous);

        return sb.toString();
    }
}