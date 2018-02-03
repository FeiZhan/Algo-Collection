class Solution {
    public boolean isIsomorphic(String s, String t) {
        if (null == s && null == t) {
            return true;
        } else if (null == s || null == t || s.length() != t.length()) {
            return false;
        }

        Map<Character, Character> sToT = new HashMap<Character, Character>();
        Map<Character, Character> tToS = new HashMap<Character, Character>();
        for (int i = 0; i < s.length(); i++) {
            if (sToT.containsKey(s.charAt(i))) {
                if (sToT.get(s.charAt(i)) != t.charAt(i)) {
                    return false;
                }
            } else {
                sToT.put(s.charAt(i), t.charAt(i));
            }
            if (tToS.containsKey(t.charAt(i))) {
                if (tToS.get(t.charAt(i)) != s.charAt(i)) {
                    return false;
                }
            } else {
                tToS.put(t.charAt(i), s.charAt(i));
            }
        }
        return true;
    }
}