class Solution {
    public long largestSquareArea(int[][] bottomLeft, int[][] topRight) {
        int length = bottomLeft.length;
        int maxEdge = 0;
        for (int i = 0; i < length; i++) {
            int bottom0 = bottomLeft[i][0];
            int left0 = bottomLeft[i][1];
            int top0 = topRight[i][0];
            int right0 = topRight[i][1];
            for (int j = i + 1; j < length; j++) {
                int bottom1 = bottomLeft[j][0];
                int left1 = bottomLeft[j][1];
                int top1 = topRight[j][0];
                int right1 = topRight[j][1];
                if (left0 >= right1 || right0 <= left1 || top0 <= bottom1 || bottom0 >= top1) {
                    continue;
                }
                int bottom = Math.max(bottom0, bottom1);
                int left = Math.max(left0, left1);
                int top = Math.min(top0, top1);
                int right = Math.min(right0, right1);
                int edge = Math.min(top - bottom, right - left);
                maxEdge = Math.max(maxEdge, edge);
            }
        }

        return (long)maxEdge * (long)maxEdge;
    }
}