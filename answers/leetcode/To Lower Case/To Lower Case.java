class Solution {
    public String toLowerCase(String str) {
        StringBuilder sb = new StringBuilder();
        for (char c : str.toCharArray()) {
            if (c >= 'A' && c <= 'Z') {
                c += 'a' - 'A';
            }
            sb.append(c);
        }
        return sb.toString();
    }
}