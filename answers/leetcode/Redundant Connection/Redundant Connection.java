class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        int[] result = new int[2];
        Map<Integer, Integer> rootMap = new HashMap<>();
        Map<Integer, Set<Integer>> memberMap = new HashMap<>();
        for (int[] edge : edges) {
            if (rootMap.containsKey(edge[0]) && rootMap.containsKey(edge[1]) && rootMap.get(edge[0]) == rootMap.get(edge[1])) {
                result[0] = edge[0];
                result[1] = edge[1];
            }
            if (!rootMap.containsKey(edge[0])) {
                rootMap.put(edge[0], edge[0]);
                Set<Integer> members = memberMap.getOrDefault(edge[0], new HashSet<>());
                members.add(edge[0]);
                memberMap.put(edge[0], members);
            }
            if (!rootMap.containsKey(edge[1])) {
                rootMap.put(edge[1], edge[1]);
                Set<Integer> members = memberMap.getOrDefault(edge[1], new HashSet<>());
                members.add(edge[1]);
                memberMap.put(edge[1], members);
            }
            if (rootMap.get(edge[0]) < rootMap.get(edge[1])) {
                int root = rootMap.get(edge[0]);
                int oldRoot = rootMap.get(edge[1]);
                Set<Integer> members = memberMap.get(oldRoot);
                for (int member : members) {
                    rootMap.put(member, root);
                }
                memberMap.get(root).addAll(members);
                memberMap.remove(oldRoot);
                //System.out.println("Merge " + edge[1] + "(" + oldRoot + ") into " + edge[0] + "(" + root + ")");
            } else if (rootMap.get(edge[0]) > rootMap.get(edge[1])) {
                int root = rootMap.get(edge[1]);
                int oldRoot = rootMap.get(edge[0]);
                Set<Integer> members = memberMap.get(oldRoot);
                for (int member : members) {
                    rootMap.put(member, root);
                }
                memberMap.get(root).addAll(members);
                memberMap.remove(oldRoot);
                //System.out.println("Merge " + edge[0] + "(" + oldRoot + ") into " + edge[1] + "(" + root + ")");
            }
        }
        return result;
    }
}