class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int count = 0;
        int[] result = new int[seq.length()];
        for (int i = 0; i < seq.length(); i++) {
            if (seq.charAt(i) == '(') {
                count++;
                result[i] = count % 2;
            } else {
                result[i] = count % 2;
                count--;
            }
        }
        return result;
    }
}