class Solution {
    public boolean checkRecord(String s) {
        int a = 0;
        int l = 0;
        for (char c : s.toCharArray()) {
            switch (c) {
                case 'A':
                    l = 0;
                    a++;
                    if (a > 1) {
                        return false;
                    }
                    break;
                case 'L':
                    l++;
                    if (l > 2) {
                        return false;
                    }
                    break;
                default:
                    l = 0;
                    break;
            }
        }
        return true;
    }
}