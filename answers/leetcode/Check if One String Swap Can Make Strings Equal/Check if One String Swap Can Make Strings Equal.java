class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        if (s1 == null && s2 == null) {
            return true;
        } else if (s1 == null || s2 == null || s1.length() != s2.length()) {
            return false;
        }

        int length = s1.length();
        List<Integer> diffIndexes = new LinkedList<>();
        for (int i = 0; i < length; i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                diffIndexes.add(i);
            }
            if (diffIndexes.size() > 2) {
                return false;
            }
        }
        if (diffIndexes.size() == 0) {
            return true;
        } else if (diffIndexes.size() == 1) {
            return false;
        } else {
            char c10 = s1.charAt(diffIndexes.get(0));
            char c11 = s1.charAt(diffIndexes.get(1));
            char c20 = s2.charAt(diffIndexes.get(0));
            char c21 = s2.charAt(diffIndexes.get(1));
            return c10 == c21 && c11 == c20;
        }
    }
}