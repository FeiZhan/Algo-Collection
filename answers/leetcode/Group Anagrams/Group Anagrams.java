class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> anagramMap = new HashMap<>();
        for (String str : strs) {
            char[] chars = str.toCharArray();
            Arrays.sort(chars);
            String sorted = String.valueOf(chars);
            List<String> anagrams = anagramMap.getOrDefault(sorted, new LinkedList<>());
            anagrams.add(str);
            anagramMap.put(sorted, anagrams);
        }

        return new LinkedList<>(anagramMap.values());
    }
}
//Runtime: 6 ms, faster than 84.22% of Java online submissions for Group Anagrams.
//Memory Usage: 41.8 MB, less than 95.49% of Java online submissions for Group Anagrams.
