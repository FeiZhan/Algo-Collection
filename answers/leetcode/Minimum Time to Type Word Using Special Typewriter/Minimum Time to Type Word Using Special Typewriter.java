class Solution {
    public int minTimeToType(String word) {
        int time = 0;
        char previous = 'a';

        for (char c : word.toCharArray()) {
            int diff = Math.abs(c - previous);
            time += Math.min(diff, 26 - diff) + 1;
            previous = c;
        }

        return time;
    }
}