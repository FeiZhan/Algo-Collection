class Solution {
    public List<String> removeAnagrams(String[] words) {
        List<String> result = new LinkedList<>();
        result.add(words[0]);

        String previous = null;

        for (String word : words) {
            char[] chars = word.toCharArray();
            Arrays.sort(chars);
            String sorted = new String(chars);

            if (previous != null && !sorted.equals(previous)) {
                result.add(word);
            }
            previous = sorted;
        }

        return result;
    }
}
//Runtime: 5 ms, faster than 71.56% of Java online submissions for Find Resultant Array After Removing Anagrams.
//Memory Usage: 44.5 MB, less than 83.96% of Java online submissions for Find Resultant Array After Removing Anagrams.
