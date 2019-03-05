class Solution {
    public boolean isLongPressedName(String name, String typed) {
        int index = 0;
        for (char c : typed.toCharArray()) {
            if (index < name.length() && c == name.charAt(index)) {
                index = Math.min(index + 1, name.length());
            } else if (index > 0 && c == name.charAt(index - 1)) {
                continue;
            } else {
                return false;
            }
        }
        return index == name.length();
    }
}