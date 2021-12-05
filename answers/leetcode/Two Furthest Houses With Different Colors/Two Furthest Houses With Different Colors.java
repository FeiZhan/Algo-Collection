class Solution {
    public int maxDistance(int[] colors) {
        int result = 0;
        for (int i = colors.length - 1; i >= 0; i--) {
            if (colors[0] != colors[i]) {
                result = Math.max(result, i);
                break;
            }
        }
        for (int i = 0; i < colors.length; i++) {
            if (colors[i] != colors[colors.length - 1]) {
                result = Math.max(result, colors.length - i - 1);
                break;
            }
        }

        return result;
    }
}
//Runtime: 0 ms, faster than 100.00% of Java online submissions for Two Furthest Houses With Different Colors.
//Memory Usage: 39.1 MB, less than 16.50% of Java online submissions for Two Furthest Houses With Different Colors.
