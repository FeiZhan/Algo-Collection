class Solution {
    public boolean isValidSerialization(String preorder) {
        String[] splitted = preorder.split(",");
        int count = 1;
        for (String s : splitted) {
            if (count <= 0) {
                return false;
            }
            if (s.length() == 1 && s.charAt(0) == '#') {
                count--;
            } else {
                count++;
            }
        }
        return count == 0;
    }
}