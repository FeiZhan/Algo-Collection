import java.util.SortedMap;
import java.util.SortedSet;

class Solution {
    public String longestWord(String[] words) {
        SortedMap<Integer, Set<String>> lengths = new TreeMap<>();
        Set<String> temp = new HashSet<>();
        temp.add("");
        lengths.put(0, temp);
        for (String word : words) {
            int length = word.length();
            Set<String> set = lengths.getOrDefault(length, new HashSet<>());
            set.add(word);
            lengths.put(length, set);
        }
        SortedSet<String> dictionary = new TreeSet<>();
        dictionary.add("");
        for (int length : lengths.keySet()) {
            for (String word0 : lengths.get(length)) {
                for (String word1 : lengths.getOrDefault(length - 1, new HashSet<>())) {
                    if (!dictionary.contains(word1)) {
                        continue;
                    }
                    StringBuilder sb = new StringBuilder(word0);
                    for (int i = 0; i + 1 < length; i++) {
                        if (word0.charAt(i) != word1.charAt(i)) {
                            sb.deleteCharAt(i);
                            break;
                        }
                    }
                    if (sb.length() > word1.length()) {
                        sb.deleteCharAt(word1.length());
                    }
                    if (sb.toString().equals(word1)) {
                        dictionary.add(word0);
                        break;
                    }
                }
            }
        }
        String longest = "";
        for (String word : dictionary) {
            if (word.length() > longest.length()) {
                longest = word;
            }
        }
        return longest;
    }
}