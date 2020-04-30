class Solution {
    public boolean checkIfExist(int[] arr) {
        Set<Integer> numbers = new HashSet<>();
        for (int number : arr) {
            if (numbers.contains(number * 2) || (number % 2 == 0 && numbers.contains(number / 2))) {
                return true;
            }
            numbers.add(number);
        }
        return false;
    }
}