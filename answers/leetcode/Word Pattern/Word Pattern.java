class Solution {
    public boolean wordPattern(String pattern, String str) {
        Map<Character, String> wordMap = new HashMap<Character, String>();
        int i;
        int j;
        for (i = 0, j = 0; i < pattern.length() && j < str.length(); i++) {
            int index = str.indexOf(' ', j);
            index = index >= 0 ? index : str.length();
            String subString = str.substring(j, index);
            if (wordMap.containsKey(pattern.charAt(i))) {
                if (!subString.equals(wordMap.get(pattern.charAt(i)))) {
                    return false;
                }
            } else {
                wordMap.put(pattern.charAt(i), subString);
            }
            j = index + 1;
        }

        if (i < pattern.length() || j < str.length()) {
            return false;
        }

        Set<String> wordSet = new HashSet<String>(wordMap.values());
        return wordMap.size() == wordSet.size();
    }
}