class Solution {
    public boolean buddyStrings(String A, String B) {
        if (A.length() != B.length()) {
            return false;
        }
        List<Integer> different = new LinkedList<>();
        Map<Character, Integer> counts = new HashMap<>();
        for (int i = 0; i < A.length(); i++) {
            if (A.charAt(i) != B.charAt(i)) {
                different.add(i);
            } else {
                char c = A.charAt(i);
                counts.put(c, counts.getOrDefault(c, 0) + 1);
            }
            if (different.size() > 2) {
                return false;
            }
        }
        if (different.size() == 2) {
            return A.charAt(different.get(0)) == B.charAt(different.get(1)) && A.charAt(different.get(1)) == B.charAt(different.get(0));
        } else if (different.size() == 0) {
            for (int count : counts.values()) {
                if (count >= 2) {
                    return true;
                }
            }
            return false;
        } else {
            return false;
        }
    }
}