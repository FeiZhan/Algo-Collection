import java.util.SortedMap;

class Solution {
    public String sortSentence(String s) {
        String[] split = s.split(" ");
        SortedMap<Integer, String> map = new TreeMap<>();

        for (String word : split) {
            int length = word.length() - 1;
            int index = Character.getNumericValue(word.charAt(length));
            map.put(index, word.substring(0, length));
        }

        return String.join(" ", map.values());
    }
}