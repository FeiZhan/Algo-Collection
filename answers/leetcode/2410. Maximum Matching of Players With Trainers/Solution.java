class Solution {
    public int matchPlayersAndTrainers(int[] players, int[] trainers) {
        Arrays.sort(players);
        Arrays.sort(trainers);
        int result = 0;
        for (int i = players.length - 1, j = trainers.length - 1; i >= 0 && j >= 0; i--) {
            if (players[i] <= trainers[j]) {
                result++;
                j--;
            }
        }

        return result;
    }
}