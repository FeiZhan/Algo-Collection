class Solution {
    public int maxFreeTime(int eventTime, int k, int[] startTime, int[] endTime) {
        List<Integer> gaps = new ArrayList<>();
        gaps.add(startTime[0]);
        for (int i = 1; i < startTime.length; i++) {
            gaps.add(startTime[i] - endTime[i - 1]);
        }
        gaps.add(eventTime - endTime[endTime.length - 1]);
        int left = 0;
        int sum = 0;
        int result = 0;
        for (int i = 0; i < gaps.size(); i++) {
            sum += gaps.get(i);
            if (i - left > k) {
                sum -= gaps.get(left);
                left++;
            }
            result = Math.max(result, sum);
        }

        return result;
    }
}