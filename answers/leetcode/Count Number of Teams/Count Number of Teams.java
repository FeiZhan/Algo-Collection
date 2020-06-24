class Solution {
    public int numTeams(int[] rating) {
        int count = 0;
        for (int i = 0; i < rating.length; i++) {
            int a = rating[i];
            for (int j = i + 1; j < rating.length; j++) {
                int b = rating[j];
                for (int k = j + 1; k < rating.length; k++) {
                    int c = rating[k];
                    if ((a > b && b > c) || (a < b && b < c)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
}