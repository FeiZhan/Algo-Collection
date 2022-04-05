import java.util.SortedMap;

class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        SortedMap<Integer, Integer> loses = new TreeMap<>();
        for (int[] match : matches) {
            loses.put(match[0], loses.getOrDefault(match[0], 0));
            loses.put(match[1], loses.getOrDefault(match[1], 0) + 1);
        }

        List<List<Integer>> result = new LinkedList<>();
        result.add(new LinkedList<>());
        result.add(new LinkedList<>());

        for (int index : loses.keySet()) {
            int lose = loses.get(index);
            if (lose <= 1) {
                result.get(lose).add(index);
            }
        }

        return result;
    }
}
//Runtime: 351 ms, faster than 20.44% of Java online submissions for Find Players With Zero or One Losses.
//Memory Usage: 108.5 MB, less than 90.61% of Java online submissions for Find Players With Zero or One Losses.
