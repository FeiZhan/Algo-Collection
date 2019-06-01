class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int i;
        for (i = 0; i + 1 < bits.length;) {
            if (bits[i] == 0) {
                i++;
            } else {
                i += 2;
            }
        }
        return i + 1 == bits.length;
    }
}