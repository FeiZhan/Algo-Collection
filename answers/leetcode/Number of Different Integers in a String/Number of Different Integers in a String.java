class Solution {
    public int numDifferentIntegers(String word) {
        int left = 0;
        int state = 0;
        Set<String> numbers = new HashSet<>();

        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            if (Character.isDigit(c)) {
                switch (state) {
                    case 0:
                        if (c == '0') {
                            state = 1;
                        } else {
                            left = i;
                            state = 2;
                        }
                        break;
                    case 1:
                        if (c != '0') {
                            left = i;
                            state = 2;
                        }
                        break;
                }
            } else {
                if (state == 1) {
                    numbers.add("0");
                    state = 0;
                } else if (state == 2) {
                    String number = word.substring(left, i);
                    numbers.add(number);
                    state = 0;
                }
            }
        }

        if (state == 1) {
            numbers.add("0");
        } else if (state == 2) {
            numbers.add(word.substring(left));
        }

        return numbers.size();
    }
}