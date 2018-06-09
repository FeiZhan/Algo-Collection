class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> charMap = new HashMap<>();
        for (char c : s.toCharArray()) {
            charMap.put(c, charMap.getOrDefault(c, 0) + 1);
        }
        return charMap.entrySet()
            .stream()
            .sorted(Map.Entry.<Character, Integer>comparingByValue().reversed())
            .map(entry -> new String(new char[entry.getValue()])
                 .replace("\0", Character.toString(entry.getKey())))
            .collect(Collectors.joining(""));
            
    }
}