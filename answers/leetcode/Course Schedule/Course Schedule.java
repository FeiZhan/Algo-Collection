class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        Map<Integer, List<Integer>> prereqMap = new HashMap<>();
        for (int[] prereq : prerequisites) {
            if (!prereqMap.containsKey(prereq[0])) {
                prereqMap.put(prereq[0], new ArrayList<>());
            }
            prereqMap.get(prereq[0]).add(prereq[1]);
        }
        Set<Integer> courseSet = new HashSet<>();
        for (int i = 0; i < numCourses; i ++) {
            if (!courseSet.contains(i)) {
                Set<Integer> path = new HashSet<>();
                if (this.dfs(i, path, courseSet, prereqMap)) {
                    courseSet.addAll(path);
                } else {
                    return false;
                }
            }
        }
        return true;
    }
    
    private boolean dfs(int current, Set<Integer> path, Set<Integer> courseSet, Map<Integer, List<Integer>> prereqMap) {
        if (courseSet.contains(current) || !prereqMap.containsKey(current)) {
            return true;
        } else if (path.contains(current)) {
            return false;
        }
        
        path.add(current);
        for (int prereq : prereqMap.get(current)) {
            if (!this.dfs(prereq, path, courseSet, prereqMap)) {
                return false;
            }
        }
        path.remove(current);
        return true;
    }
}