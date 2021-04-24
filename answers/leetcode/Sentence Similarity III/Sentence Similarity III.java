class Solution {
    public boolean areSentencesSimilar(String sentence1, String sentence2) {
        String[] words1 = sentence1.split(" ");
        String[] words2 = sentence2.split(" ");
        int length = Math.min(words1.length, words2.length);

        int prefixCount = length;
        for (int i = 0; i < length; i++) {
            if (!words1[i].equals(words2[i])) {
                prefixCount = i;
                //System.out.println(prefixCount + ": " + words1[i] + " != " + words2[i]);
                break;
            }
        }

        int postfixCount = length;
        for (int i = 0; i < length; i++) {
            if (!words1[words1.length - i - 1].equals(words2[words2.length - i - 1])) {
                postfixCount = i;
                //System.out.println(postfixCount + ": " + words1[words1.length - i - 1] + " != " + words2[words2.length - i - 1]);
                break;
            }
        }

        int sum = prefixCount + postfixCount;
        return sum >= words1.length || sum >= words2.length;
    }
}