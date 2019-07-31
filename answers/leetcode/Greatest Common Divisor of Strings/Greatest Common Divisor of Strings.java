class Solution {
    public String gcdOfStrings(String str1, String str2) {
        for (int i = 0; i < str1.length() && i < str2.length(); i++) {
            if (str1.charAt(i) != str2.charAt(i)) {
                return "";
            }
        }
        int length = this.gcd(str1.length(), str2.length());
        while (length > 0) {
            boolean flag = true;
            String common = str1.substring(0, length);
            for (int i = 0; i + length < str1.length() || i + length < str2.length(); i += length) {
                if ((i + length < str1.length() && !str1.substring(i, i + length).equals(common))
                    || (i + length < str2.length() && !str2.substring(i, i + length).equals(common))) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return common;
            }
            length--;
        }
        return "";
    }
    
    private static int gcd(int number1, int number2) {
        if(number2 == 0){
            return number1;
        }
        return gcd(number2, number1%number2);
    }
}