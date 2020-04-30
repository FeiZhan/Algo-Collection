class Solution {
    public int maximum69Number (int num) {
        StringBuilder sb = new StringBuilder(Integer.toString(num));
        int index = sb.indexOf("6");
        if (index >= 0) {
            sb.setCharAt(index, '9');
        }
        return Integer.parseInt(sb.toString());
    }
}