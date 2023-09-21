class Solution {
    public List<String> splitWordsBySeparator(List<String> words, char separator) {
        List<String> result = new LinkedList<>();
        for (String word : words) {
            String[] split = word.split("\\" + separator);
            for (String str : split) {
                if (str.length() > 0) {
                    result.add(str);
                }
            }
        }

        return result;
    }
}