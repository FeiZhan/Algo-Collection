class Solution {
    
    private int previous = 0;
    private int[] squares = new int[1000000];
    public int numSquares(int n) {
        if (this.squares[n] == 0) {
            for (int i = previous; i <= n; i++) {
                if (i == 0 || this.squares[i] > 0) {
                    for (int j = 0; j * j <= n; j++) {
                        int num = i + j * j;
                        if (num > 0 && this.squares[num] == 0) {
                            this.squares[num] = this.squares[i] + 1;
                        } else {
                            this.squares[num] = Math.min(this.squares[num], this.squares[i] + 1);
                        }
                    }
                }
            }
        }
        return this.squares[n];
    }
}