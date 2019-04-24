class Solution {
    public List<String> commonChars(String[] A) {
        Map<Character, Integer> common = new HashMap<>();
        for (char c : A[0].toCharArray()) {
            common.put(c, common.getOrDefault(c, 0) + 1);
        }
        for (int i = 1; i < A.length; i++) {
            Map<Character, Integer> chars = new HashMap<>();
            for (char c : A[i].toCharArray()) {
                chars.put(c, chars.getOrDefault(c, 0) + 1);
            }
            for (char c : common.keySet()) {
                int count = Math.min(common.get(c), chars.getOrDefault(c, 0));
                common.put(c, count);
            }
        }
        List<String> results = new LinkedList<>();
        for (char c : common.keySet()) {
            for (int i = 0; i < common.get(c); i++) {
                results.add(Character.toString(c));
            }
        }
        return results;
    }
}