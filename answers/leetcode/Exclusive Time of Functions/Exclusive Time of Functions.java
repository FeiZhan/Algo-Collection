class Solution {
    public int[] exclusiveTime(int n, List<String> logs) {
        int[] results = new int[n];
        Map<Integer, Integer> startTimes = new HashMap<>();
        Stack<Integer> stack = new Stack<>();
        for (String log : logs) {
            String[] splitLog = log.split(":");
            int id = Integer.parseInt(splitLog[0]);
            int timestamp = Integer.parseInt(splitLog[2]);
            if (splitLog[1].equals("start")) {
                if (!stack.isEmpty()) {
                    int parentId = stack.peek();
                    if (startTimes.containsKey(parentId)) {
                        results[parentId] += timestamp - startTimes.get(parentId);
                    }
                    startTimes.put(parentId, timestamp);
                }
                stack.push(id);
                startTimes.put(id, timestamp);
            } else {
                if (!stack.isEmpty() && stack.peek() == id && startTimes.containsKey(id)) {
                    results[id] += timestamp - startTimes.get(id) + 1;
                    stack.pop();
                    if (!stack.isEmpty()) {
                        int parentId = stack.peek();
                        startTimes.put(parentId, timestamp + 1);
                    }
                } else {
                    System.out.println("Error");
                }
            }
        }
        return results;
    }
}