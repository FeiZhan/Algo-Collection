class Solution {
    public int closetTarget(String[] words, String target, int startIndex) {
        int shortest = Integer.MAX_VALUE;
        for (int i = 0; i < words.length; i++) {
            if (target.equals(words[i])) {
                shortest = Math.min(shortest, Math.abs(i - startIndex));
                shortest = Math.min(shortest, words.length - Math.abs(i - startIndex));
            }
        }

        return shortest != Integer.MAX_VALUE ? shortest : -1;
    }
}