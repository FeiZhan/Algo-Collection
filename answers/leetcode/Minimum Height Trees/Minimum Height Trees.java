class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        Map<Integer, Set<Integer>> nodeMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            nodeMap.put(i, new HashSet<>());
        }
        for (int[] edge : edges) {
            Set<Integer> nodeSet = nodeMap.getOrDefault(edge[0], new HashSet<>());
            nodeSet.add(edge[1]);
            nodeMap.put(edge[0], nodeSet);
            nodeSet = nodeMap.getOrDefault(edge[1], new HashSet<>());
            nodeSet.add(edge[0]);
            nodeMap.put(edge[1], nodeSet);
        }
        while (nodeMap.size() > 2) {
            List<Integer> removed = new LinkedList<>();
            for (int node : nodeMap.keySet()) {
                if (nodeMap.get(node).size() <= 1) {
                    removed.add(node);
                }
            }
            for (int node : removed) {
                Set<Integer> nodeSet = nodeMap.get(node);
                for (int target : nodeSet) {
                    if (nodeMap.containsKey(target)) {
                        nodeMap.get(target).remove(node);
                    }
                }
                nodeMap.remove(node);
            }
        }
        return new ArrayList<>(nodeMap.keySet());
    }
}