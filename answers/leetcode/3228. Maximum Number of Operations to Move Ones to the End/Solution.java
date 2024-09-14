class Solution {
    public int maxOperations(String s) {
        boolean isZero = false;
        int count = 0;
        int result = 0;

        for (char c : s.toCharArray()) {
            switch (c) {
                case '0':
                    if (!isZero) {
                        result += count;
                    }
                    isZero = true;
                    break;
                case '1':
                    isZero = false;
                    count++;
                    break;
            }
        }

        return result;
    }
}