import java.util.SortedMap;

class Solution {
    public int numFactoredBinaryTrees(int[] A) {
        final int MOD = 1_000_000_007;
        SortedMap<Integer, Long> numberMap = new TreeMap<>();
        for (int number : A) {
            numberMap.put(number, 1l);
        }
        for (int number : numberMap.keySet()) {
            long count = 0;
            for (int factor : numberMap.keySet()) {
                if (factor >= number) {
                    break;
                }
                if (number % factor == 0 && numberMap.containsKey(number / factor)) {
                    int factor1 = number / factor;
                    count += numberMap.get(factor) * numberMap.get(factor1);
                    //System.out.println(number + " == " + factor + " * " + factor1 + ": " + count);
                }
            }
            numberMap.put(number, numberMap.get(number) + count);
            //System.out.println(number + " " + numberMap.get(number));
        }
        long result = 0;
        for (long value : numberMap.values()) {
            result += value;
        }
        return (int) (result % MOD);
    }
}