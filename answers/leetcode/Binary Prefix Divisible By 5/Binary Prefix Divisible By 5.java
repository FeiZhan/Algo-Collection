class Solution {
    public List<Boolean> prefixesDivBy5(int[] A) {
        int number = 0;
        List<Boolean> result = new LinkedList<>();
        for (int bit : A) {
            number = (number * 2 + bit) % 10;
            result.add(number == 0 || number == 5);
        }
        return result;
    }
}