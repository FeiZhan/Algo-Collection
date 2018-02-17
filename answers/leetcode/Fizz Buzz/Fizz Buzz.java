class Solution {
    public List<String> fizzBuzz(int n) {
        List<String> numbers = new ArrayList<String>();
        for (int i = 1, fizz = 1, buzz = 1; i <= n; i++, fizz++, buzz++) {
            String number = Integer.toString(i);
            if (3 == fizz && 5 == buzz) {
                number = "FizzBuzz";
                fizz = 0;
                buzz = 0;
            } else if (3 == fizz) {
                number = "Fizz";
                fizz = 0;
            } else if (5 == buzz) {
                number = "Buzz";
                buzz = 0;
            }
            numbers.add(number);
        }
        return numbers;
    }
}