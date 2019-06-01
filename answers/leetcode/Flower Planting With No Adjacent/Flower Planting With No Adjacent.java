class Solution {
    public int[] gardenNoAdj(int N, int[][] paths) {
        Map<Integer, Set<Integer>> pathMap = new HashMap<>();
        for (int[] path : paths) {
            Set<Integer> pathSet = pathMap.getOrDefault(path[0], new HashSet<>());
            pathSet.add(path[1]);
            pathMap.put(path[0], pathSet);
            pathSet = pathMap.getOrDefault(path[1], new HashSet<>());
            pathSet.add(path[0]);
            pathMap.put(path[1], pathSet);

        }
        int[] result = new int[N];
        for (int i = 0; i < N; i++) {
            if (result[i] == 0) {
                this.dfs(i + 1, result, pathMap);
            }
        }
        return result;
    }

    private void dfs(int index, int[] result, Map<Integer, Set<Integer>> pathMap) {
        Set<Integer> adjacent = pathMap.getOrDefault(index, new HashSet<>());
        boolean[] colors = new boolean[4];
        for (int node : adjacent) {
            if (result[node - 1] > 0) {
                colors[result[node - 1] - 1] = true;
            }
        }
        for (int i = 0; i < colors.length; i++) {
            if (!colors[i]) {
                result[index - 1] = i + 1;
                break;
            }
        }
        for (int node : adjacent) {
            if (result[node - 1] == 0) {
                //System.out.println(index + " -> " + node);
                this.dfs(node, result, pathMap);
            }
        }
    }
}