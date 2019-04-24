class Solution {
    public int bitwiseComplement(int N) {
        int ones = 1;
        while (ones < N) {
            ones = (ones << 1) + 1;
        }
        return ones - N;
    }
}