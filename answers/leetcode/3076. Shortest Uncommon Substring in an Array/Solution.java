import java.util.SortedMap;

class Solution {
    public String[] shortestSubstrings(String[] arr) {
        Map<String, Integer> countMap = new HashMap<>();
        Map<Integer, SortedMap<String, Integer>> substringMap = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            String string = arr[i];
            SortedMap<String, Integer> substrings = new TreeMap<>(
                Comparator.comparing(String::length).thenComparing(String::toString));
            for (int j = 0; j < string.length(); j++) {
                for (int k = j; k < string.length(); k++) {
                    String substring = string.substring(j, k + 1);
                    countMap.put(substring, countMap.getOrDefault(substring, 0) + 1);
                    substrings.put(substring, substrings.getOrDefault(substring, 0) + 1);
                }
            }
            substringMap.put(i, substrings);
        }

        String[] result = new String[arr.length];
        for (int i = 0; i < arr.length; i++) {
            SortedMap<String, Integer> substrings = substringMap.get(i);
            for (String substring : substrings.keySet()) {
                int count = substrings.get(substring);
                if (countMap.get(substring) == count) {
                    result[i] = substring;
                    break;
                }
            }
            if (result[i] == null) {
                result[i] = "";
            }
        }

        return result;
    }
}