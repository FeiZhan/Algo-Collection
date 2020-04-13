class Solution {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        List<List<Integer>> result = new LinkedList<>();
        Map<Integer, List<Integer>> groups = new HashMap<>();
        for (int i = 0; i < groupSizes.length; i++) {
            int size = groupSizes[i];
            List<Integer> group = groups.getOrDefault(size, new LinkedList<>());
            group.add(i);
            if (group.size() == size) {
                result.add(group);
                group = new LinkedList<>();
            }
            groups.put(size, group);
        }
        return result;
    }
}