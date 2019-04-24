class Solution {
    public int[] diStringMatch(String S) {
        int length = S.length();
        int min = 0;
        int max = length;
        int[] results = new int[length + 1];
        for (int i = 0; i < length; i++) {
            char c = S.charAt(i);
            switch (c) {
                case 'I':
                    results[i] = min;
                    min++;
                    break;
                case 'D':
                    results[i] = max;
                    max--;
                    break;
            }
        }
        results[length] = min;
        return results;
    }
}