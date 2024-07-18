class Solution {
    public String sortVowels(String s) {
        Set<Character> VOWELS = new HashSet<>();
        for (char c : "AEIOUaeiou".toCharArray()) {
            VOWELS.add(c);
        }
        PriorityQueue<Character> queue = new PriorityQueue<>();
        for (char c : s.toCharArray()) {
            if (VOWELS.contains(c)) {
                queue.add(c);
            }
        }

        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            sb.append(VOWELS.contains(c) ? queue.poll() : c);
        }

        return sb.toString();
    }
}