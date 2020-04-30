class Solution {
    public String reformat(String s) {
        List<Character> digits = new LinkedList<>();
        List<Character> letters = new LinkedList<>();
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                digits.add(c);
            } else if (Character.isLetter(c)) {
                letters.add(c);
            }
        }
        if (Math.abs(digits.size() - letters.size()) > 2
            || (digits.size() - letters.size() > 1 && letters.size() == 0)
            || (letters.size() - digits.size() > 1 && digits.size() == 0)) {
            return "";
        }
        boolean shouldUseDigit = digits.size() >= letters.size();
        StringBuilder sb = new StringBuilder();
        for (int i = 0, j = 0; i < digits.size() || j < letters.size();) {
            if (shouldUseDigit && i < digits.size()) {
                sb.append(digits.get(i));
                i++;
            } else if (!shouldUseDigit && j < letters.size()) {
                sb.append(letters.get(j));
                j++;
            }
            shouldUseDigit = !shouldUseDigit;
        }
        return sb.toString();
    }
}