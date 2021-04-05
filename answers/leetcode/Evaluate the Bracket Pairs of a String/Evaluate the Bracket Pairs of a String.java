class Solution {
    public String evaluate(String s, List<List<String>> knowledge) {
        Map<String, String> knowledgeMap = new HashMap<>();
        for (List<String> pairs : knowledge) {
            knowledgeMap.put(pairs.get(0), pairs.get(1));
        }

        int right = -1;
        int length = s.length();
        StringBuilder sb = new StringBuilder(s);
        for (int i = length - 1; i >= 0; i--) {
            char c = s.charAt(i);
            if (c == ')') {
                right = i;
            } else if (c == '(' && right >= 0) {
                String key = s.substring(i + 1, right);
                String value = knowledgeMap.getOrDefault(key, "?");
                sb.replace(i, right + 1, value);
                right = -1;
            }
        }

        return sb.toString();
    }
}