class Solution {
    public boolean isCircularSentence(String sentence) {
        String[] split = sentence.split(" ");
        for (int i = 1; i < split.length; i++) {
            String previous = split[i - 1];
            if (previous.charAt(previous.length() - 1) != split[i].charAt(0)) {
                return false;
            }
        }

        String last = split[split.length - 1];
        return split[0].charAt(0) == last.charAt(last.length() - 1);
    }
}