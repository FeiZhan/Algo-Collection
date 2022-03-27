class Solution {
    public List<String> cellsInRange(String s) {
        List<String> result = new LinkedList<>();
        for (char i = s.charAt(0); i <= s.charAt(3); i++) {
            for (char j = s.charAt(1); j <= s.charAt(4); j++) {
                String cell = Character.toString(i) + j;
                result.add(cell);
            }
        }

        return result;
    }
}
//Runtime: 8 ms, faster than 80.00% of Java online submissions for Cells in a Range on an Excel Sheet.
//Memory Usage: 48 MB, less than 20.00% of Java online submissions for Cells in a Range on an Excel Sheet.
