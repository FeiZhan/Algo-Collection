class Solution {
    public boolean checkTwoChessboards(String coordinate1, String coordinate2) {
        int c11 = (int)(coordinate1.charAt(0) - 'a');
        int c12 = Character.getNumericValue(coordinate1.charAt(1));
        int c21 = (int)(coordinate2.charAt(0) - 'a');
        int c22 = Character.getNumericValue(coordinate2.charAt(1));

        return (c11 + c12) % 2 == (c21 + c22) % 2;
    }
}