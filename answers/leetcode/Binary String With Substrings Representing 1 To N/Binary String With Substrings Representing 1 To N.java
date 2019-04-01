class Solution {
    public boolean queryString(String S, int N) {
        if (N > 0 && !this.queryString(S, N - 1)) {
            return false;
        }
        return S.indexOf(Integer.toBinaryString(N)) >= 0;
    }
}