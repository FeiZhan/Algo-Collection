class Solution {
    public int openLock(String[] deadends, String target) {
        int step = 0;
        Set<String> deadendSet = new HashSet<>(Arrays.asList(deadends));
        Queue<String> nextQueue = new LinkedList<>();
        nextQueue.add("0000");
        while (!nextQueue.isEmpty()) {
            Queue<String> currentQueue = new LinkedList<>(nextQueue);
            nextQueue = new LinkedList<>();
            while (!currentQueue.isEmpty()) {
                String lock = currentQueue.poll();
                if (lock.equals(target)) {
                    return step;
                }
                if (deadendSet.contains(lock)) {
                    continue;
                }
                for (int i = 0; i < lock.length(); i++) {
                    char digit = lock.charAt(i);
                    StringBuilder sb = new StringBuilder(lock);
                    sb.setCharAt(i, (digit != '0' ? (char)(digit - 1) : '9'));
                    nextQueue.add(sb.toString());
                    sb.setCharAt(i, (digit != '9' ? (char)(digit + 1) : '0'));
                    nextQueue.add(sb.toString());
                }
                deadendSet.add(lock);
            }
            step++;
        }
        return -1;
    }
}