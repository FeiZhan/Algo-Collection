class Solution {
    public int minimumChairs(String s) {
        int count = 0;
        int result = 0;
        for (char c : s.toCharArray()) {
            switch (c) {
                case 'E':
                    count++;
                    result = Math.max(result, count);
                    break;
                case 'L':
                    count--;
                    break;
            }
        }

        return result;
    }
}