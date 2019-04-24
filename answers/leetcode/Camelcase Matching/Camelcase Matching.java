class Solution {
    public List<Boolean> camelMatch(String[] queries, String pattern) {
        List<Boolean> results = new LinkedList<>();
        for (String query : queries) {
            boolean match = true;
            int left = 0;
            for (int i = 0; i < query.length(); i++) {
                char c = query.charAt(i);
                if (left < pattern.length() && c == pattern.charAt(left)) {
                    left++;
                } else if (left > pattern.length() || Character.isUpperCase(c)) {
                    match = false;
                    break;
                }
            }
            results.add(match && left == pattern.length());
        }
        return results;
    }
}