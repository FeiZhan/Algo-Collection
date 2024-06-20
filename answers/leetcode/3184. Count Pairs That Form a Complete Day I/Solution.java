class Solution {
    public int countCompleteDayPairs(int[] hours) {
        Map<Integer, Integer> residues = new HashMap<>();
        for (int hour : hours) {
            hour %= 24;
            residues.put(hour, residues.getOrDefault(hour, 0) + 1);
        }

        int zero = residues.getOrDefault(0, 0);
        int twelve = residues.getOrDefault(12, 0);
        int result = zero * (zero - 1) / 2 + twelve * (twelve - 1) / 2;
        for (int residue : residues.keySet()) {
            if (residue == 0 || residue >= 12) {
                continue;
            }
            result += residues.get(residue) * residues.getOrDefault(24 - residue, 0);
        }

        return result;
    }
}