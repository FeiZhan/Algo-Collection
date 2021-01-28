class Solution {
    public String interpret(String command) {
        int length = command.length();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < length; i++) {
            char c = command.charAt(i);
            if (c == '(') {
                if (i + 1 < length && command.charAt(i + 1) == ')') {
                    sb.append('o');
                    i++;
                } else if (i + 3 < length && command.charAt(i + 1) == 'a'
                    && command.charAt(i + 2) == 'l'
                    && command.charAt(i + 3) == ')') {
                        sb.append("al");
                        i += 3;
                } else {
                    sb.append(c);
                }
            } else {
                sb.append(c);
            }
        }
        return sb.toString();
    }
}