class Solution {
    public String finalString(String s) {
        boolean reversed = false;
        StringBuilder sb = new StringBuilder();

        for (char c : s.toCharArray()) {
            if (c == 'i') {
                reversed = !reversed;
            } else if (reversed) {
                sb.insert(0, c);
            } else {
                sb.append(c);
            }
        }

        if (reversed) {
            sb.reverse();
        }
        return sb.toString();
    }
}