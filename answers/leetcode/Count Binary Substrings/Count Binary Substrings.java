class Solution {
    public int countBinarySubstrings(String s) {
        int count = 0;
        List<Integer> groups = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            if (i > 0 && s.charAt(i) != s.charAt(i - 1)) {
                groups.add(count);
                count = 0;
            }
            count++;
        }
        groups.add(count);
        int result = 0;
        for (int i = 1; i < groups.size(); i++) {
            result += Math.min(groups.get(i - 1), groups.get(i));
        }
        return result;
    }
}