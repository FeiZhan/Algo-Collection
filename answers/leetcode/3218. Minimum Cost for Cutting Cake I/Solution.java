class Solution {
    public int minimumCost(int m, int n, int[] horizontalCut, int[] verticalCut) {
        Arrays.sort(horizontalCut);
        Arrays.sort(verticalCut);
        int height = 1;
        int width = 1;
        int result = 0;

        for (int i = horizontalCut.length - 1, j = verticalCut.length - 1; i >= 0 || j >= 0;) {
            if (j < 0 || (i >= 0 && horizontalCut[i] >= verticalCut[j])) {
                result += width * horizontalCut[i];
                height++;
                i--;
            } else {
                result += height * verticalCut[j];
                width++;
                j--;
            }
        }

        return result;
    }
}