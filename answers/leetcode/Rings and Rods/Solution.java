class Solution {
    public int countPoints(String rings) {
        Map<Integer, Set<Character>> points = new HashMap<>();
        for (int i = 1; i < rings.length(); i += 2) {
            int rod = Character.getNumericValue(rings.charAt(i));
            Set<Character> colors = points.getOrDefault(rod, new HashSet<>());
            colors.add(rings.charAt(i - 1));
            points.put(rod, colors);
        }

        int count = 0;
        for (Set<Character> colors : points.values()) {
            if (colors.size() >= 3) {
                count++;
            }
        }

        return count;
    }
}
//Runtime: 2 ms, faster than 30.47% of Java online submissions for Rings and Rods.
//Memory Usage: 38.8 MB, less than 28.72% of Java online submissions for Rings and Rods.
