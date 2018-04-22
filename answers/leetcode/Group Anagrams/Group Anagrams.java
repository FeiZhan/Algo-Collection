class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> anagramMap = new HashMap<>();
        for (String str : strs) {
            char[] chars = str.toCharArray();
            Arrays.sort(chars);
            String sorted = new String(chars);
            if (!anagramMap.containsKey(sorted)) {
                anagramMap.put(sorted, new LinkedList<>());
            }
            anagramMap.get(sorted).add(str);
        }
        return new ArrayList<List<String>>(anagramMap.values());
    }
}