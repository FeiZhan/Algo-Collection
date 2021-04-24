class Solution {
    public int maximumWealth(int[][] accounts) {
        int maxWealth = 0;
        for (int[] customer : accounts) {
            int sum = 0;
            for (int account : customer) {
                sum += account;
            }
            maxWealth = Math.max(maxWealth, sum);
        }

        return maxWealth;
    }
}