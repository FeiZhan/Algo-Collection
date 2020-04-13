class Solution {
    public int minimumSwap(String s1, String s2) {
        int[] cases = new int[2];
        for (int i = 0; i < s1.length() && i < s2.length(); i++) {
            char c1 = s1.charAt(i);
            char c2 = s2.charAt(i);
            if (c1 == 'x' &&  c2 == 'y') {
                cases[0]++;
            } else if (c1 == 'y' && c2 == 'x') {
                cases[1]++;
            }
        }
        int swap = 0;
        if (cases[0] >= 2) {
            swap += cases[0] / 2;
            cases[0] %= 2;
        }
        if (cases[1] >= 2) {
            swap += cases[1] / 2;
            cases[1] %= 2;
        }
        if (cases[0] > 0 && cases[1] > 0) {
            int min = Math.min(cases[0], cases[1]);
            swap += min * 2;
            cases[0] -= min;
            cases[1] -= min;
        }
        return cases[0] > 0 || cases[1] > 0 ? -1 : swap;
    }
}