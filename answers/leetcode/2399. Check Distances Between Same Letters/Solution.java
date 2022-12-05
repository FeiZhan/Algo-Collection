class Solution {
    public boolean checkDistances(String s, int[] distance) {
        Map<Integer, Integer> indexMap = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            int charIndex = (int) (s.charAt(i) - 'a');
            if (indexMap.containsKey(charIndex)) {
                if (i - indexMap.get(charIndex) - 1 != distance[charIndex]) {
                    return false;
                }
            } else {
                indexMap.put(charIndex, i);
            }
        }

        return true;
    }
}
//Runtime: 4 ms, faster than 33.75% of Java online submissions for Check Distances Between Same Letters.
//Memory Usage: 43.2 MB, less than 69.96% of Java online submissions for Check Distances Between Same Letters.
