class Solution {
    public List<String> letterCombinations(String digits) {
        final String[] PHONE = new String[]{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        List<String> combinations = new LinkedList<String>();
        combinations.add("");
        for (int i = 0; i < digits.length(); i++) {
            int num = Character.getNumericValue(digits.charAt(i));
            List<String> newCombinations = new LinkedList<String>();
            for (char c : PHONE[num].toCharArray()) {
                for (String combination : combinations) {
                    newCombinations.add(combination + c);
                }
            }
            combinations = newCombinations;
        }
        if (combinations.size() == 1) {
            combinations.remove(0);
        }
        return combinations;
    }
}