class Solution {
    public int beautifulSubstrings(String s, int k) {
        final Set<Character> VOWELS = new HashSet<>();
        VOWELS.add('a');
        VOWELS.add('e');
        VOWELS.add('i');
        VOWELS.add('o');
        VOWELS.add('u');

        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            int count = 0;
            for (int j = i; j < s.length(); j++) {
                char c = s.charAt(j);
                if (VOWELS.contains(c)) {
                    count++;
                }
                int consonantCount = j - i + 1 - count;
                if (count == consonantCount && (count * consonantCount) % k == 0) {
                    result++;
                }
            }
        }

        return result;
    }
}