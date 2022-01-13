class Solution {
    public String firstPalindrome(String[] words) {
        String result = "";
        for (String word : words) {
            boolean flag = true;
            for (int i = 0; i * 2 < word.length(); i++) {
                if (word.charAt(i) != word.charAt(word.length() - i - 1)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                result = word;
                break;
            }
        }

        return result;
    }
}
//Runtime: 3 ms, faster than 52.24% of Java online submissions for Find First Palindromic String in the Array.
//Memory Usage: 47.7 MB, less than 27.98% of Java online submissions for Find First Palindromic String in the Array.
