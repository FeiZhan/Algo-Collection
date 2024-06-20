class Solution {
    public String compressedString(String word) {
        char previous = '\0';
        int count = 0;
        StringBuilder sb = new StringBuilder();

        for (char c : word.toCharArray()) {
            if (c != previous && count > 0) {
                sb.append(compress(previous, count));
                count = 0;
            }
            previous = c;
            count++;
        }
        if (count > 0) {
            sb.append(compress(previous, count));
        }

        return sb.toString();
    }

    private StringBuilder compress(char c, int count) {
        StringBuilder sb = new StringBuilder();
        while (count >= 9) {
            sb.append(9).append(c);
            count -= 9;
        }
        if (count > 0) {
            sb.append(count).append(c);
        }

        return sb;
    }
}