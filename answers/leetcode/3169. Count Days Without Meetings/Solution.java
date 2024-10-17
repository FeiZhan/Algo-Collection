class Solution {
    public int countDays(int days, int[][] meetings) {
        Arrays.sort(meetings, (m0, m1) -> m0[0] - m1[0]);
        int end = 0;
        int result = 0;
        for (int[] meeting : meetings) {
            if (meeting[0] > end) {
                result += meeting[0] - end - 1;
            }
            end = Math.max(end, meeting[1]);
        }

        return result + Math.max(days - end, 0);
    }
}