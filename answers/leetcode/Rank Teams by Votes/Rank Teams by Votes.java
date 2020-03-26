class Solution {
    public String rankTeams(String[] votes) {
        Map<Character, List<Integer>> teams = new HashMap<>();
        for (String vote : votes) {
            for (int i = 0; i < vote.length(); i++) {
                char c = vote.charAt(i);
                List<Integer> list = teams.getOrDefault(c, new ArrayList<>());
                while (list.size() <= i) {
                    list.add(0);
                }
                list.set(i, list.get(i) + 1);
                teams.put(c, list);
            }
        }
        PriorityQueue<Character> queue = new PriorityQueue<>((t1, t2) -> {
            List<Integer> rank1 = teams.get(t1);
            List<Integer> rank2 = teams.get(t2);
            for (int i = 0; i < rank1.size() || i < rank2.size(); i++) {
                int r1 = i < rank1.size() ? rank1.get(i) : Integer.MIN_VALUE;
                int r2 = i < rank2.size() ? rank2.get(i) : Integer.MIN_VALUE;
                if (r1 != r2) {
                    return r2 - r1;
                }
            }
            return t1 - t2;
        });
        for (char key : teams.keySet()) {
            queue.add(key);
        }
        StringBuilder result = new StringBuilder();
        while (!queue.isEmpty()) {
            result.append(queue.poll());
        }
        return result.toString();
    }
}