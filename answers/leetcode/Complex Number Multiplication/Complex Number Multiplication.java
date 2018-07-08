class Solution {
    public String complexNumberMultiply(String a, String b) {
        String[] aStr = a.substring(0, a.length() - 1).split("\\+");
        int[] aInt = Arrays.stream(aStr).mapToInt(Integer::parseInt).toArray();
        String[] bStr = b.substring(0, b.length() - 1).split("\\+");
        int[] bInt = Arrays.stream(bStr).mapToInt(Integer::parseInt).toArray();
        return (aInt[0] * bInt[0] - aInt[1] * bInt[1]) + "+" + (aInt[0] * bInt[1] + aInt[1] * bInt[0]) + "i";
    }
}