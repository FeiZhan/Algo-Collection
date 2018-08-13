class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        Map<Integer, Set<Integer>> preMap = new HashMap<>();
        Map<Integer, Set<Integer>> postMap = new HashMap<>();
        for (int[] pre : prerequisites) {
            Set<Integer> preSet = preMap.getOrDefault(pre[1], new HashSet<>());
            preSet.add(pre[0]);
            preMap.put(pre[1], preSet);
            Set<Integer> postSet = postMap.getOrDefault(pre[0], new HashSet<>());
            postSet.add(pre[1]);
            postMap.put(pre[0], postSet);
        }
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (!postMap.containsKey(i)) {
                queue.offer(i);
            }
        }
        int[] order = new int[numCourses];
        int count = 0;
        while (!queue.isEmpty()) {
            int num = queue.poll();
            order[count] = num;
            count++;
            if (preMap.containsKey(num)) {
                for (int value : preMap.get(num)) {
                    if (postMap.containsKey(value)) {
                        Set<Integer> postSet = postMap.get(value);
                        postSet.remove(num);
                        if (postSet.size() == 0) {
                            postMap.remove(value);
                            queue.offer(value);
                        } else {
                            postMap.put(value, postSet);
                        }
                    }
                }
            }
        }
        if (count == numCourses) {
            return order;
        } else {
            return new int[0];
        }
    }
}