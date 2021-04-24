class Solution {
    public boolean squareIsWhite(String coordinates) {
        int column = (int) (coordinates.charAt(0) - 'a');
        int row = Character.getNumericValue(coordinates.charAt(1)) - 1;
        return (column % 2 == 1) ^ (row % 2 == 1);
    }
}