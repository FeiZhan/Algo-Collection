/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     public int f(int x, int y);
 * };
 */
class Solution {
    public List<List<Integer>> findSolution(CustomFunction customfunction, int z) {
        int x = 1;
        int y = 1000;
        List<List<Integer>> results = new LinkedList<>();
        while (x <= 1000 && y >= 1) {
            int result = customfunction.f(x, y);
            if (result > z) {
                y--;
            } else if (result < z) {
                x++;
            } else {
                List<Integer> pair = new LinkedList<>();
                pair.add(x);
                pair.add(y);
                results.add(pair);
                x++;
                y--;
            }
        }
        return results;
    }
}