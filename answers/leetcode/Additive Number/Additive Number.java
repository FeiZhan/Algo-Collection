class Solution {
    public boolean isAdditiveNumber(String num) {
        if (num == null || num.length() == 0) {
            return false;
        }
        for (int i = 1; i + 1 < num.length(); i++) {
            if (this.dfs(0, i, num)) {
                return true;
            }
        }
        return false;
    }

    private boolean dfs(int previous, int current, String number) {
        if (current + 1 == number.length()) {
            return true;
        }
        for (int i = current; i < number.length(); i++) {
            if (number.charAt(current) == '0' && i > current) {
                break;
            }
            StringBuilder sb = new StringBuilder();
            int carry = 0;
            for (int j = 0; previous + j < current || current + j <= i || carry > 0; j++) {
                int sum = carry;
                if (previous + j < current) {
                    sum += Character.getNumericValue(number.charAt(current - j - 1));
                }
                if (current + j <= i) {
                    sum += Character.getNumericValue(number.charAt(i - j));
                }
                carry = sum / 10;
                sb.insert(0, sum % 10);
            }
            //System.out.println(number.substring(previous, current) + " " + number.substring(current, i + 1) + ": " + sb.toString());
            String sum = sb.toString();
            int length = i + 1 + sum.length();
            if (length > number.length()) {
                break;
            }
            if (sum.equals(number.substring(i + 1, length)) && (length == number.length() || this.dfs(current, i + 1, number))) {
                return true;
            }
        }
        return false;
    }
}class Solution {
    public boolean isAdditiveNumber(String num) {
        if (num == null || num.length() == 0) {
            return false;
        }
        for (int i = 1; i + 1 < num.length(); i++) {
            if (this.dfs(0, i, num)) {
                return true;
            }
        }
        return false;
    }

    private boolean dfs(int previous, int current, String number) {
        if (current + 1 == number.length()) {
            return true;
        }
        for (int i = current; i < number.length(); i++) {
            if (number.charAt(current) == '0' && i > current) {
                break;
            }
            StringBuilder sb = new StringBuilder();
            int carry = 0;
            for (int j = 0; previous + j < current || current + j <= i || carry > 0; j++) {
                int sum = carry;
                if (previous + j < current) {
                    sum += Character.getNumericValue(number.charAt(current - j - 1));
                }
                if (current + j <= i) {
                    sum += Character.getNumericValue(number.charAt(i - j));
                }
                carry = sum / 10;
                sb.insert(0, sum % 10);
            }
            //System.out.println(number.substring(previous, current) + " " + number.substring(current, i + 1) + ": " + sb.toString());
            String sum = sb.toString();
            int length = i + 1 + sum.length();
            if (length > number.length()) {
                break;
            }
            if (sum.equals(number.substring(i + 1, length)) && (length == number.length() || this.dfs(current, i + 1, number))) {
                return true;
            }
        }
        return false;
    }
}