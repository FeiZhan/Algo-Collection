class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int X) {
        int maxSecret = 0;
        int result = 0;
        int secret = 0;
        for (int i = 0; i < customers.length; i++) {
            result += grumpy[i] == 0 ? customers[i] : 0;
            secret += grumpy[i] == 1 ? customers[i] : 0;
            if (i >= X) {
                secret -= grumpy[i - X] == 1 ? customers[i - X] : 0;
            }
            maxSecret = Math.max(maxSecret, secret);
            //System.out.println(i + " " + customers[i] + ": " + result + " " + secret + " " + maxSecret);
        }
        return result + maxSecret;
    }
}