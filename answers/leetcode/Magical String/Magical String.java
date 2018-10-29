class Solution {
    public int magicalString(int n) {
        StringBuilder sb = new StringBuilder("122");
        int index = 2;
        while (sb.length() < n) {
            char c = sb.charAt(index);
            char alternative = sb.charAt(sb.length() - 1) == '1' ? '2' : '1';
            int count = Character.getNumericValue(c);
            for (int i = 0; i < count; i++) {
                sb.append(alternative);
            }
            index++;
        }
        System.out.println(sb.toString());
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (sb.charAt(i) == '1') {
                count++;
            }
        }
        return count;
    }
}