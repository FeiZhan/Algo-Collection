class Solution {
    public boolean lemonadeChange(int[] bills) {
        int[] counts = new int[3];
        for (int bill : bills) {
            int change = bill - 5;
            while (change >= 20 && counts[2] > 0) {
                change -= 20;
                counts[2]--;
            }
            while (change >= 10 && counts[1] > 0) {
                change -= 10;
                counts[1]--;
            }
            while (change >= 5 && counts[0] > 0) {
                change -= 5;
                counts[0]--;
            }
            if (change != 0) {
                return false;
            }
            if (bill == 20) {
                counts[2]++;
            } else if (bill == 10) {
                counts[1]++;
            } else {
                counts[0]++;
            }
        }
        return true;
    }
}