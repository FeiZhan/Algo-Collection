class Solution {
    public boolean doesAliceWin(String s) {
        Set<Character> vowelSet = new HashSet<>();
        vowelSet.add('a');
        vowelSet.add('e');
        vowelSet.add('i');
        vowelSet.add('o');
        vowelSet.add('u');

        for (char c : s.toCharArray()) {
            if (vowelSet.contains(c)) {
                return true;
            }
        }

        return false;
    }
}