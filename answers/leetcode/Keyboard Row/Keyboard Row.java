class Solution {

    private static final String[] KEYBOARD = new String[] {
        "QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"
    };
    public String[] findWords(String[] words) {
        List<String> matches = new LinkedList<>();
        for (String word : words) {
            int rowNum = -1;
            for (int i = 0; i < KEYBOARD.length; i++) {
                if (KEYBOARD[i].indexOf(Character.toUpperCase(word.charAt(0))) >= 0) {
                    rowNum = i;
                    break;
                }
            }
            boolean match = true;
            for (char c : word.toCharArray()) {
                c = Character.toUpperCase(c);
                if (KEYBOARD[rowNum].indexOf(c) < 0) {
                    match = false;
                    break;
                }
            }
            if (match) {
                matches.add(word);
            }
        }
        return matches.toArray(new String[matches.size()]);
    }
}