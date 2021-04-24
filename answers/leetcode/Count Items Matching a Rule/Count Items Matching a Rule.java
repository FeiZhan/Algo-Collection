class Solution {
    public int countMatches(List<List<String>> items, String ruleKey, String ruleValue) {
        int count = 0;
        for (List<String> item : items) {
            int index = ruleKey.equals("type") ? 0 : ruleKey.equals("color") ? 1 : 2;
            count += item.get(index).equals(ruleValue) ? 1 : 0;
        }

        return count;
    }
}