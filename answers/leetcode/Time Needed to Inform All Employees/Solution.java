class Solution {
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        Map<Integer, List<Integer>> managers = new HashMap<>();
        for (int i = 0; i < manager.length; i++) {
            int m = manager[i];
            if (m >= 0) {
                List<Integer> employees = managers.getOrDefault(m, new LinkedList<>());
                employees.add(i);
                managers.put(m, employees);
            }
        }
        return dfs(headID, managers, informTime);
    }

    private int dfs(int current, Map<Integer, List<Integer>> managers, int[] informTime) {
        if (!managers.containsKey(current)) {
            return 0;
        }

        int maxTime = 0;
        for (int employee : managers.get(current)) {
            int time = this.dfs(employee, managers, informTime);
            maxTime = Math.max(maxTime, time);
        }

        return maxTime + informTime[current];
    }
}
//Runtime: 158 ms, faster than 45.90% of Java online submissions for Time Needed to Inform All Employees.
//Memory Usage: 126.7 MB, less than 30.38% of Java online submissions for Time Needed to Inform All Employees.
