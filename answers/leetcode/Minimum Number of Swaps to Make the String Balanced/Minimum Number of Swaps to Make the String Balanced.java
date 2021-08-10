class Solution {
    public int minSwaps(String s) {
        int left = 0;
        int swap = 0;

        for (char c : s.toCharArray()) {
            switch (c) {
                case '[':
                    left++;
                    break;
                case ']':
                    if (left > 0) {
                        left--;
                    } else {
                        left++;
                        swap++;
                    }
                    break;
            }
        }

        return swap;
    }
}