class Solution {
    public int maxRepeating(String sequence, String word) {
        int result = 1;
        StringBuilder sb = new StringBuilder(word);
        while (sequence.contains(sb.toString())) {
            result++;
            sb.append(word);
        }

        return result - 1;
    }
}