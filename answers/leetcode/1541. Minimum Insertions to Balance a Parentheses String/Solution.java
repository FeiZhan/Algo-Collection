class Solution {
    public int minInsertions(String s) {
        int count = 0;
        int result = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') {
                if (count % 2 == 1) {
                    count--;
                    result++;
                }
                count += 2;
            } else {
                count -= 1;
            }
            while (count < 0) {
                result++;
                count += 2;
            }
        }
        return result + count;
    }
}