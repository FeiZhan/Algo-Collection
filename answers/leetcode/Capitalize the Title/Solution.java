class Solution {
    public String capitalizeTitle(String title) {
        String[] split = title.split(" ");
        StringBuilder sb = new StringBuilder();

        for (String word : split) {
            word = word.toLowerCase();
            if (word.length() > 2) {
                word = Character.toUpperCase(word.charAt(0)) + word.substring(1);
            }
            sb.append(word).append(' ');
        }
        if (sb.length() > 0) {
            sb.deleteCharAt(sb.length() - 1);
        }

        return sb.toString();
    }
}
//Runtime: 10 ms, faster than 43.09% of Java online submissions for Capitalize the Title.
//Memory Usage: 43.3 MB, less than 5.98% of Java online submissions for Capitalize the Title.
