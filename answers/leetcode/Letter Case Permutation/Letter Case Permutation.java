class Solution {
    public List<String> letterCasePermutation(String S) {
        List<String> permutation = new LinkedList<String>();
        permutation.add(S);
        for (int i = 0; i < S.length(); i++) {
            char c = S.charAt(i);
            if (Character.isLetter(c)) {
                char change = Character.isUpperCase(c) ? Character.toLowerCase(c) : Character.toUpperCase(c);
                int size = permutation.size();
                for (int j = 0; j < size; j++) {
                    StringBuilder sb = new StringBuilder(permutation.get(j));
                    sb.setCharAt(i, change);
                    permutation.add(sb.toString());
                }
            }
        }
        return permutation;
    }
}