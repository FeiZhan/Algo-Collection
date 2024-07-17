class Solution {
    public int numberOfBeams(String[] bank) {
        if (bank == null || bank.length < 2) {
            return 0;
        }

        int previous = 0;
        int result = 0;
        for (int i = 0; i < bank.length; i++) {
            int current = 0;
            for (char c : bank[i].toCharArray()) {
                current += c == '1' ? 1 : 0;
            }
            if (current > 0) {
                if (previous > 0) {
                    result += previous * current;
                }
                previous = current;
            }
        }

        return result;
    }
}