/* The guess API is defined in the parent class GuessGame.
   @param num, your guess
   @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
      int guess(int num); */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int left = 1;
        int right = n;
        while (left < right) {
            int middle = left + (right - left) / 2;
            int result = guess(middle);
            if (0 == result) {
                return middle;
            } else if (result > 0) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        return left;
    }
}