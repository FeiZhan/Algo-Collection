import java.util.SortedMap;

class Solution {
    public String arrangeWords(String text) {
        String[] split = text.split(" ");
        SortedMap<Integer, List<String>> lengthMap = new TreeMap<>();
        for (String word : split) {
            int length = word.length();
            List<String> list = lengthMap.getOrDefault(length, new LinkedList<>());
            list.add(word.toLowerCase());
            lengthMap.put(length, list);
        }
        StringBuilder sb = new StringBuilder();
        for (List<String> value : lengthMap.values()) {
            for (String word : value) {
                sb.append(' ').append(word);
            }
        }
        if (sb.length() > 0) {
            if (sb.charAt(0) == ' ') {
                sb.deleteCharAt(0);
            }
            if (sb.length() > 0 && Character.isLetter(sb.charAt(0))) {
                sb.setCharAt(0, Character.toUpperCase(sb.charAt(0)));
            }
        }
        return sb.toString();
    }
}