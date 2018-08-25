class Solution {
    
    private static final String[] NUMBERS = {"Zero", "One", "Two", "Three", "Four", "Five",
                                             "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
                                             "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                                             "Seventeen", "Eighteen", "Nineteen"};
    private static final String[] TENS = {"x", "x", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
                                         "Eighty", "Ninety"};
    private static final String[] THOUSANDS = {"", "Thousand", "Million", "Billion"};
    
    public String numberToWords(int num) {
        StringBuilder sb = new StringBuilder();
        if (num < NUMBERS.length) {
            sb.append(NUMBERS[num]);
        } else if (num < 100) {
            sb.append(TENS[num / 10]);
            if (num % 10 > 0) {
                sb.append(" ").append(NUMBERS[num % 10]);
            }
        } else if (num < 1000) {
            sb.append(this.numberToWords(num / 100)).append(" Hundred");
            if (num % 100 > 0) {
                sb.append(" ").append(this.numberToWords(num % 100));
            }
        } else {
            int count = 0;
            while (num > 0) {
                if (num % 1000 > 0) {
                    if (count > 0) {
                        if (sb.length() > 0) {
                            sb.insert(0, " ");
                        }
                        sb.insert(0, THOUSANDS[count]).insert(0, " ");
                    }
                    sb.insert(0, this.numberToWords(num % 1000));
                }
                count++;
                num /= 1000;
            }
        }
        return sb.toString();
    }
}