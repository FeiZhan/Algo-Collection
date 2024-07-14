class Solution {
    public List<Boolean> checkIfPrerequisite(int numCourses, int[][] prerequisites, int[][] queries) {
        Map<Integer, Set<Integer>> preMap = new HashMap<>();
        for (int[] prerequisite : prerequisites) {
            int before = prerequisite[0];
            int after = prerequisite[1];
            Set<Integer> set = preMap.getOrDefault(before, new HashSet<>());
            set.add(after);
            preMap.put(before, set);
        }

        List<Boolean> result = new LinkedList<>();
        for (int[] query : queries) {
            result.add(dfs(query[0], query[1], new HashSet<>(), preMap));
        }

        return result;
    }

    private boolean dfs(int current, int target, Set<Integer> visited, Map<Integer, Set<Integer>> preMap) {
        if (current == target) {
            return true;
        } else if (visited.contains(current) || !preMap.containsKey(current)) {
            return false;
        }

        visited.add(current);
        Set<Integer> set = preMap.get(current);
        for (int next : set) {
            if (dfs(next, target, visited, preMap)) {
                return true;
            }
        }

        return false;
    }
}