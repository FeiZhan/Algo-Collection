class Solution {
    public int canBeTypedWords(String text, String brokenLetters) {
        int count = 0;
        String[] split = text.split(" ");

        for (String word : split) {
            boolean flag = false;
            for (char c : brokenLetters.toCharArray()) {
                if (word.indexOf(c) >= 0) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                count++;
            }
        }

        return count;
    }
}