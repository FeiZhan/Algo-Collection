class Solution {
    public int numTilePossibilities(String tiles) {
        Map<Character, Integer> counts = new HashMap<>();
        for (char c : tiles.toCharArray()) {
            counts.put(c, counts.getOrDefault(c, 0) + 1);
        }
        int count = 0;
        for (int i = 1; i <= tiles.length(); i++) {
            count += this.getPossibilities(counts, i);
        }
        return count;
    }

    private int getPossibilities(Map<Character, Integer> counts, int length) {
        if (length == 1) {
            return counts.size();
        }
        int total = 0;
        for (char c : counts.keySet()) {
            int count = counts.get(c);
            Map<Character, Integer> temp = new HashMap<>(counts);
            if (count == 1) {
                temp.remove(c);
            } else {
                temp.put(c, count - 1);
            }
            total += this.getPossibilities(temp, length - 1);
        }
        return total;
    }
}