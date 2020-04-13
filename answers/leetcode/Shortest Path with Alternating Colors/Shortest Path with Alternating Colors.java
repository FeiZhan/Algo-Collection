class Solution {
    public int[] shortestAlternatingPaths(int n, int[][] red_edges, int[][] blue_edges) {
        Map<Integer, Set<Integer>> blueEdgeMap = new HashMap<>();
        for (int[] edge : blue_edges) {
            Set<Integer> edgeSet = blueEdgeMap.getOrDefault(edge[0], new HashSet<>());
            edgeSet.add(edge[1]);
            blueEdgeMap.put(edge[0], edgeSet);
        }
        Map<Integer, Set<Integer>> redEdgeMap = new HashMap<>();
        for (int[] edge : red_edges) {
            Set<Integer> edgeSet = redEdgeMap.getOrDefault(edge[0], new HashSet<>());
            edgeSet.add(edge[1]);
            redEdgeMap.put(edge[0], edgeSet);
        }
        int[][] paths = new int[n][2];
        for (int i = 0; i < paths.length; i++) {
            for (int j = 0; j < paths[i].length; j++) {
                paths[i][j] = Integer.MAX_VALUE;
            }
        }
        paths[0][0] = 0;
        paths[0][1] = 0;
        Queue<Integer> nextQueue = new LinkedList<>();
        nextQueue.add(0);
        while (!nextQueue.isEmpty()) {
            Queue<Integer> queue = nextQueue;
            nextQueue = new LinkedList<>();
            while (!queue.isEmpty()) {
                int current = queue.poll();
                Set<Integer> edgeSet = blueEdgeMap.getOrDefault(current, new HashSet<>());
                for (int next : edgeSet) {
                    if (paths[current][1] < Integer.MAX_VALUE && paths[current][1] + 1 < paths[next][0]) {
                        paths[next][0] = paths[current][1] + 1;
                        nextQueue.add(next);
                    }
                }
                edgeSet = redEdgeMap.getOrDefault(current, new HashSet<>());
                for (int next : edgeSet) {
                    if (paths[current][0] < Integer.MAX_VALUE && paths[current][0] + 1 < paths[next][1]) {
                        paths[next][1] = paths[current][0] + 1;
                        nextQueue.add(next);
                    }
                }
            }
        }
        int[] result = new int[n];
        for (int i = 0; i < result.length; i++) {
            System.out.println(i + ": " + paths[i][0] + " " + paths[i][1]);
            result[i] = Math.min(paths[i][0], paths[i][1]);
            if (result[i] == Integer.MAX_VALUE) {
                result[i] = -1;
            }
        }
        return result;
    }
}