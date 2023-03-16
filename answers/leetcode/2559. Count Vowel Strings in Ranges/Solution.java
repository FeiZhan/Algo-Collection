class Solution {
    public int[] vowelStrings(String[] words, int[][] queries) {
        final Set<Character> VOWELS = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u'));
        int[] counts = new int[words.length + 1];

        for (int i = 0; i < words.length; i++) {
            String word = words[i];
            counts[i + 1] = counts[i];
            if (VOWELS.contains(word.charAt(0)) && VOWELS.contains(word.charAt(word.length() - 1))) {
                counts[i + 1]++;
            }
        }

        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int[] query = queries[i];
            result[i] = counts[query[1] + 1] - counts[query[0]];
        }

        return result;
    }
}