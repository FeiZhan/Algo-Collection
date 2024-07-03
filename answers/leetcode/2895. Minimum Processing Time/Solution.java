class Solution {
    public int minProcessingTime(List<Integer> processorTime, List<Integer> tasks) {
        Collections.sort(processorTime);
        Collections.sort(tasks, Collections.reverseOrder());
        int result = 0;
        for (int i = 0; i < processorTime.size(); i++) {
            int maxTime = 0;
            for (int j = 0; j < 4; j++) {
                maxTime = Math.max(maxTime, tasks.get(i * 4 + j));
            }
            result = Math.max(result, maxTime + processorTime.get(i));
        }

        return result;
    }
}