class Solution {
    public double[] calcEquation(String[][] equations, double[] values, String[][] queries) {
        Map<String, Map<String, Double>> edgeMap = new HashMap<>();
        for (int i = 0; i < equations.length; i++) {
            Map<String, Double> nodeMap = edgeMap.getOrDefault(equations[i][0], new HashMap<>());
            nodeMap.put(equations[i][1], values[i]);
            edgeMap.put(equations[i][0], nodeMap);
            nodeMap = edgeMap.getOrDefault(equations[i][1], new HashMap<>());
            nodeMap.put(equations[i][0], 1. / values[i]);
            edgeMap.put(equations[i][1], nodeMap);
        }
        for (String node : edgeMap.keySet()) {
            if (!edgeMap.get(node).containsKey(node)) {
                edgeMap.get(node).put(node, 1.);
            }
        }

        double[] results = new double[queries.length];
        for (int i = 0; i < queries.length; i++) {
            this.dfs(queries[i][0], queries[i][1], edgeMap, new HashSet<>());
            if (edgeMap.containsKey(queries[i][0]) && edgeMap.get(queries[i][0]).containsKey(queries[i][1])) {
                results[i] = edgeMap.get(queries[i][0]).get(queries[i][1]);
            } else {
                results[i] = -1.;
            }
        }
        return results;
    }

    private void dfs(String a, String b, Map<String, Map<String, Double>> edgeMap, Set<String> visited) {
        if (!visited.contains(a) && !a.equals(b) && edgeMap.containsKey(a)) {
            visited.add(a);
            Map<String, Double> nodeMap = edgeMap.get(a);
            if (nodeMap.containsKey(b)) {
                return;
            }
            for (String key : nodeMap.keySet()) {
                this.dfs(key, b, edgeMap, visited);
                if (edgeMap.containsKey(key) && edgeMap.get(key).containsKey(b)) {
                    edgeMap.get(a).put(b, nodeMap.get(key) * edgeMap.get(key).get(b));
                    break;
                }
            }
        }
    }
}