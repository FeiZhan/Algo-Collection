class Solution {
    public boolean checkValidString(String s) {
        int min = 0;
        int max = 0;
        for (char c : s.toCharArray()) {
            switch (c) {
                case '(':
                    min++;
                    max++;
                    break;
                case ')':
                    min--;
                    max--;
                    break;
                case '*':
                    min--;
                    max++;
                    break;
            }
            if (max < 0) {
                return false;
            }
            min = Math.max(min, 0);
            //System.out.println(c + " " + min + " " + max);
        }
        return min <= 0 && max >= 0;
    }
}
