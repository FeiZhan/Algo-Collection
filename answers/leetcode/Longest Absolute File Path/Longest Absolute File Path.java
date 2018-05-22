class Solution {
    public int lengthLongestPath(String input) {
        String[] lines = input.split("\n");
        int longest = 0;
        for (int i = 0; i < lines.length; i++) {
            if (lines[i].charAt(0) != '\t') {
                int length = this.dfs(i, lines);
                longest = Math.max(longest, length);
            }
        }
        return longest;
    }
    
    private int dfs(int index, String[] lines) {
        int indents = 0;
        for (int i = 0; i < lines[index].length(); i++) {
            if ('\t' == lines[index].charAt(i)) {
                indents++;
            } else {
                break;
            }
        }
        int longest = 0;
        for (int i = index + 1; i < lines.length; i++) {
            int localIndents = 0;
            for (int j = 0; j < lines[i].length(); j++) {
                if ('\t' == lines[i].charAt(j)) {
                    localIndents++;
                } else {
                    break;
                }
            }
            if (indents + 1 == localIndents) {
                int length = this.dfs(i, lines);
                longest = Math.max(longest, length);
            } else if (indents + 1 > localIndents) {
                break;
            }
        }
        if (0 == longest && lines[index].indexOf('.') == -1) {
            return 0;
        }
        //System.out.println(index + " " + lines[index] + ": " + (lines[index].length() - indents) + ", " + longest);
        return lines[index].length() - indents + longest + (longest == 0 ? 0 : 1);
    }
}