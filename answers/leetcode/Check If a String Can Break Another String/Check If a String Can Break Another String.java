class Solution {
    public boolean checkIfCanBreak(String s1, String s2) {
        char[] chars1 = s1.toCharArray();
        Arrays.sort(chars1);
        char[] chars2 = s2.toCharArray();
        Arrays.sort(chars2);
        boolean lessThan = true;
        for (int i = 0; i < chars1.length; i++) {
            if (chars1[i] != chars2[i]) {
                lessThan = chars1[i] < chars2[i];
                break;
            }
        }
        for (int i = 0; i < chars1.length; i++) {
            if ((lessThan && chars1[i] > chars2[i]) || (!lessThan && chars1[i] < chars2[i])) {
                return false;
            }
        }
        return true;
    }
}