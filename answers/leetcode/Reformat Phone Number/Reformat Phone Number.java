class Solution {
    public String reformatNumber(String number) {
        int count = 0;
        StringBuilder sb = new StringBuilder();

        for (char c : number.toCharArray()) {
            if (Character.isDigit(c)) {
                count++;
                sb.append(c);
                if (count >= 3) {
                    sb.append('-');
                    count = 0;
                }
            }
        }

        if (count == 0 && sb.length() >= 1) {
            sb.deleteCharAt(sb.length() - 1);
        } else if (count == 1 && sb.length() >= 2) {
            sb.deleteCharAt(sb.length() - 2);
            sb.insert(sb.length() - 2, '-');
        }

        return sb.toString();
    }
}