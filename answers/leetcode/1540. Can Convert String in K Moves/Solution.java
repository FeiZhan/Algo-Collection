class Solution {
    public boolean canConvertString(String s, String t, int k) {
        if (s.length() != t.length()) {
            return false;
        }

        int length = s.length();
        Map<Integer, Integer> diffMap = new HashMap<>();
        for (int i = 0; i < length; i++) {
            int diff = (int)(t.charAt(i) - s.charAt(i));
            if (diff == 0) {
                continue;
            } else if (diff < 0) {
                diff += 26;
            }
            if (diff + diffMap.getOrDefault(diff, 0) * 26 > k) {
                return false;
            }
            diffMap.put(diff, diffMap.getOrDefault(diff, 0) + 1);
        }

        return true;
    }
}