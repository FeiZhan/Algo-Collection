class Solution {
    public int videoStitching(int[][] clips, int T) {
        Arrays.sort(clips, (a, b) -> a[0] - b[0]);
        int count = 1;
        int left = 0;
        int right = 0;
        for (int[] clip : clips) {
            if (clip[0] > left && clip[1] > right) {
                if (right >= T) {
                    return count;
                } else if (clip[0] > right) {
                    return -1;
                }
                left = right;
                count++;
            }
            right = Math.max(right, clip[1]);
            //System.out.println(clip[0] + " - " + clip[1] + ": " + count + " " + left + " - " + right);
        }
        return right >= T ? count : -1;
    }
}