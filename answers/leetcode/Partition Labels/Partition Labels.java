class Solution {
    public List<Integer> partitionLabels(String S) {
        Map<Character, List<Integer>> charMap = new HashMap<>();
        for (int i = 0; i < S.length(); i++) {
            char c = S.charAt(i);
            if (!charMap.containsKey(c)) {
                List<Integer> list = new ArrayList<>();
                list.add(i);
                list.add(i);
                charMap.put(c, list);
            } else {
                charMap.get(c).set(1, i);
            }
        }
        int start = 0;
        int end = 0;
        List<Integer> result = new LinkedList<>();
        for (int i = 0; i < S.length(); i++) {
            if (i > end) {
                result.add(i - start);
                start = i;
            }
            char c = S.charAt(i);
            end = Math.max(end, charMap.get(c).get(1));
        }
        result.add(S.length() - start);
        return result;
    }
}