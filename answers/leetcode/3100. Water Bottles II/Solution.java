class Solution {
    public int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty = 0;
        int result = 0;
        while (numBottles > 0) {
            result += numBottles;
            empty += numBottles;
            numBottles = 0;
            while (empty >= numExchange) {
                empty -= numExchange;
                numBottles++;
                numExchange++;
            }
        }

        return result;
    }
}