class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        Map<Integer, Integer> indegreeMap = new HashMap<>();
        Map<Integer, List<Integer>> preMap = new HashMap<>();
        for (int[] prerequisite : prerequisites) {
            int before = prerequisite[1];
            int after = prerequisite[0];
            indegreeMap.put(after, indegreeMap.getOrDefault(after, 0) + 1);
            List<Integer> list = preMap.getOrDefault(before, new LinkedList<>());
            list.add(after);
            preMap.put(before, list);
        }

        Queue<Integer> nextQueue = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (!indegreeMap.containsKey(i)) {
                nextQueue.add(i);
            }
        }
        Set<Integer> visited = new LinkedHashSet<>();
        while (!nextQueue.isEmpty()) {
            Queue<Integer> queue = new LinkedList<>(nextQueue);
            nextQueue.clear();
            while (!queue.isEmpty()) {
                int current = queue.poll();
                if (visited.contains(current)) {
                    continue;
                }
                visited.add(current);
                List<Integer> children = preMap.getOrDefault(current, new LinkedList<>());
                for (int child : children) {
                    indegreeMap.put(child, indegreeMap.get(child) - 1);
                    if (indegreeMap.get(child) == 0) {
                        indegreeMap.remove(child);
                        nextQueue.add(child);
                    }
                }
            }
        }

        if (visited.size() < numCourses) {
            return new int[0];
        }
        int index = 0;
        int[] result = new int[numCourses];
        for (int course : visited) {
            result[index] = course;
            index++;
        }

        return result;
    }
}