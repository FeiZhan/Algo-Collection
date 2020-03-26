class Solution {
    public List<String> printVertically(String s) {
        String[] words = s.split(" ");
        int maxLength = 0;
        for (String word : words) {
            maxLength = Math.max(maxLength, word.length());
        }
        List<String> result = new LinkedList<>();
        for (int i = 0; i < maxLength; i++) {
            StringBuilder sb = new StringBuilder();
            for (String word : words) {
                sb.append(word.length() > i ? word.charAt(i) : ' ');
            }
            result.add(sb.toString().replaceAll("\\s+$", ""));
        }
        return result;
    }
}