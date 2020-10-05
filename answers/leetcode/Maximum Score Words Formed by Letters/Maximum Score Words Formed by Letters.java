class Solution {
    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        Map<Character, Integer> letterCounts = new HashMap<>();
        for (char c : letters) {
            letterCounts.put(c, letterCounts.getOrDefault(c, 0) + 1);
        }
        Map<Character, Integer> scores = new HashMap<>();
        for (int i = 0; i < score.length; i++) {
            scores.put((char)(i + 'a'), score[i]);
        }
        return this.dfs(0, letterCounts, words, scores);
    }

    private int dfs(int index, Map<Character, Integer> letterCounts, final String[] words, final Map<Character, Integer> scores) {
        if (index >= words.length) {
            return 0;
        }

        int score = 0;
        String word = words[index];
        Map<Character, Integer> nextCounts = new HashMap<>(letterCounts);
        for (char c : word.toCharArray()) {
            if (!nextCounts.containsKey(c)) {
                score = 0;
                break;
            }
            score += scores.getOrDefault(c, 0);
            nextCounts.put(c, nextCounts.get(c) - 1);
            if (nextCounts.get(c) == 0) {
                nextCounts.remove(c);
            }
        }
        if (score > 0) {
            score += this.dfs(index + 1, nextCounts, words, scores);
        }
        return Math.max(score, this.dfs(index + 1, letterCounts, words, scores));
    }
}