class Solution {

    private static final char[] HEX = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

    public String toHex(int num) {
        StringBuilder sb = new StringBuilder();
        while (num != 0) {
            sb.insert(0, HEX[num & 15]);
            num >>>= 4;
        }
        return sb.length() > 0 ? sb.toString() : "0";
    }
}