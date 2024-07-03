class Solution {
    public long minimumSteps(String s) {
        long ones = 0l;
        long result = 0l;
        for (char c : s.toCharArray()) {
            switch (c) {
                case '0':
                    result += ones;
                    break;
                case '1':
                    ones++;
                    break;
            }
        }

        return result;
    }
}