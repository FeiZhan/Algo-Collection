class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int empty = 0;
        int result = 0;
        while (numBottles > 0) {
            result += numBottles;
            empty += numBottles;
            numBottles = empty / numExchange;
            empty %= numExchange;
        }

        return result;
    }
}