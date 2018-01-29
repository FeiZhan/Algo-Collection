class Solution {
    private static final Set<Character> VOWELS = new HashSet<Character>(Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'));
    
    public String reverseVowels(String s) {
        if (null == s) {
            return s;
        }
        
        char[] sentence = s.toCharArray();
        int left = 0;
        int right = sentence.length - 1;
        while (left < right) {
            if (! VOWELS.contains(sentence[left])) {
                left++;
            } else if (! VOWELS.contains(sentence[right])) {
                right--;
            } else {
                char temp = sentence[left];
                sentence[left] = sentence[right];
                sentence[right] = temp;
                left++;
                right--;
            }
        }
        return new String(sentence);
    }
}