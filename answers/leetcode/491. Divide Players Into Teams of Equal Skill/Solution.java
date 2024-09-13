class Solution {
    public long dividePlayers(int[] skill) {
        int sum = 0;
        Map<Integer, Integer> skillMap = new HashMap<>();
        for (int s : skill) {
            sum += s;
            skillMap.put(s, skillMap.getOrDefault(s, 0) + 1);
        }

        sum = sum * 2 / skill.length;
        long result = 0l;
        for (int s : skillMap.keySet()) {
            while (skillMap.get(s) > 0) {
                int mate = sum - s;
                if (!skillMap.containsKey(mate) || skillMap.get(mate) <= 0) {
                    return -1l;
                }
                result += s * mate;
                skillMap.put(mate, skillMap.get(mate) - 1);
                skillMap.put(s, skillMap.get(s) - 1);
            }
        }

        return result;
    }
}