class Solution {
    public String decodeString(String s) {
        StringBuilder sb = this.decodeString(s, 0, s.length() - 1);
        return sb.toString();
    }
    
    private StringBuilder decodeString(String s, int start, int end) {
        StringBuilder sb = new StringBuilder();
        int count = 0;
        for (int i = start; i <= end; i++) {
            char c = s.charAt(i);
            if (Character.isDigit(c)) {
                count = count * 10 + Character.getNumericValue(c);
            } else if (c == '[') {
                int j = i;
                int leftCount = 1;
                while (leftCount > 0 && j <= end) {
                    j++;
                    if (s.charAt(j) == '[') {
                        leftCount++;
                    } else if (s.charAt(j) == ']') {
                        leftCount--;
                    }
                }
                StringBuilder segment = this.decodeString(s, i + 1, j - 1);
                //System.out.println(i + " - " + j + ": " + segment.toString() + " * " + count);
                while (count-- > 0) {
                    sb.append(segment);
                }
                count = 0;
                i = j;
            } else {
                sb.append(c);
            }
        }
        //System.out.println(start + " - " + end + ": " + sb.toString());
        return sb;
    }
}