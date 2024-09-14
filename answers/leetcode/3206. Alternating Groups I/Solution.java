class Solution {
    public int numberOfAlternatingGroups(int[] colors) {
        int length = colors.length;
        if (colors == null || length < 3) {
            return 0;
        }

        int result = 0;
        for (int i = 2; i < length; i++) {
            result += colors[i - 2] != colors[i - 1] && colors[i - 1] != colors[i] ? 1 : 0;
        }
        result += colors[length - 1] != colors[0] && colors[0] != colors[1] ? 1 : 0;
        result += colors[length - 2] != colors[length - 1] && colors[length - 1] != colors[0] ? 1 : 0;

        return result;
    }
}