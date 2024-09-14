class Solution {
    public String findLatestTime(String s) {
        List<Integer> numbers = new ArrayList<>();
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                numbers.add(Character.getNumericValue(c));
            } else if (c == '?') {
                numbers.add(-1);
            }
        }

        if (numbers.get(0) == -1) {
            if (numbers.get(1) <= 1) {
                numbers.set(0, 1);
            } else {
                numbers.set(0, 0);
            }
        }
        if (numbers.get(1) == -1) {
            if (numbers.get(0) == 0) {
                numbers.set(1, 9);
            } else {
                numbers.set(1, 1);
            }
        }
        if (numbers.get(2) == -1) {
            numbers.set(2, 5);
        }
        if (numbers.get(3) == -1) {
            numbers.set(3, 9);
        }
        
        StringBuilder sb = new StringBuilder();
        for (int number : numbers) {
            sb.append(number);
        }
        sb.insert(2, ':');

        return sb.toString();
    }
}