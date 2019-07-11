class Solution {
    public String[] findOcurrences(String text, String first, String second) {
        String[] words = text.split(" ");
        List<String> results = new LinkedList<>();
        for (int i = 2; i < words.length; i++) {
            if (words[i - 2].equals(first) && words[i - 1].equals(second)) {
                results.add(words[i]);
            }
        }
        return results.toArray(new String[results.size()]);
    }
}