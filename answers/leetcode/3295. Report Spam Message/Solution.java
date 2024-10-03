class Solution {
    public boolean reportSpam(String[] message, String[] bannedWords) {
        Set<String> bannedSet = new HashSet<>();
        for (String banned : bannedWords) {
            bannedSet.add(banned);
        }
        int count = 0;
        for (String word : message) {
            count += bannedSet.contains(word) ? 1 : 0;
            if (count >= 2) {
                return true;
            }
        }

        return count >= 2;
    }
}