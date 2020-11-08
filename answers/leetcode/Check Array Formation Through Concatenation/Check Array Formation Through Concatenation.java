class Solution {
    public boolean canFormArray(int[] arr, int[][] pieces) {
        Map<Integer, Integer> pieceStart = new HashMap<>();
        for (int i = 0; i < pieces.length; i++) {
            pieceStart.put(pieces[i][0], i);
        }
        for (int i = 0; i < arr.length; i++) {
            if (!pieceStart.containsKey(arr[i])) {
                return false;
            }
            int index = pieceStart.get(arr[i]);
            for (int j = 0; j < pieces[index].length; j++) {
                if (arr.length <= i + j || arr[i + j] != pieces[index][j]) {
                    return false;
                }
            }
            pieceStart.remove(arr[i]);
            i += pieces[index].length - 1;
        }
        return true;
    }
}