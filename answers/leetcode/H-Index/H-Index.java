class Solution {
    public int hIndex(int[] citations) {
        int[] indices = new int[citations.length + 1];
        for (int citation : citations) {
            indices[Math.min(citation, indices.length - 1)]++;
        }
        int sum = 0;
        for (int i = indices.length - 1; i >= 0; i--) {
            sum += indices[i];
            if (sum >= i) {
                return i;
            }
        }
        return 0;
    }
}