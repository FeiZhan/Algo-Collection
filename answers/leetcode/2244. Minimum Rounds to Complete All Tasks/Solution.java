class Solution {
    public int minimumRounds(int[] tasks) {
        Map<Integer, Integer> counts = new HashMap<>();
        for (int task : tasks) {
            counts.put(task, counts.getOrDefault(task, 0) + 1);
        }

        int result = 0;
        for (int count : counts.values()) {
            result += count / 3;
            int residue = count % 3;
            if (residue == 2 || (residue == 1 && count > 3)) {
                result++;
            } else if (residue == 1) {
                return -1;
            }
        }

        return result;
    }
}
//Runtime: 57 ms, faster than 16.15% of Java online submissions for Minimum Rounds to Complete All Tasks.
//Memory Usage: 103.7 MB, less than 5.35% of Java online submissions for Minimum Rounds to Complete All Tasks.
