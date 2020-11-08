class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        Map<Character, List<Integer>> chars = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            List<Integer> list = chars.getOrDefault(c, new ArrayList<>());
            if (list.size() < 2) {
                list.add(i);
            } else {
                list.set(1, i);
            }
            chars.put(c, list);
        }
        int maxLength = -1;
        for (List<Integer> list : chars.values()) {
            if (list.size() >= 2) {
                maxLength = Math.max(maxLength, list.get(1) - list.get(0) - 1);
            }
        }
        return maxLength;
    }
}