class Solution {
    public String convertDateToBinary(String date) {
        StringBuilder sb = new StringBuilder();
        String[] split = date.split("-");
        for (int i = 0; i < split.length; i++) {
            int number = Integer.parseInt(split[i]);
            StringBuilder sb1 = new StringBuilder();
            while (number > 0) {
                sb1.insert(0, number % 2);
                number /= 2;
            }
            if (i > 0) {
                sb.append("-");
            }
            sb.append(sb1);
        }

        return sb.toString();
    }
}