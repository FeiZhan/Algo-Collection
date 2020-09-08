class Solution {

    private static final String[] MONTHS = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    public String reformatDate(String date) {
        String[] split = date.split(" ");
        StringBuilder sb = new StringBuilder(split[2]);
        sb.append('-');
        for (int i = 0; i < MONTHS.length; i++) {
            if (split[1].equals(MONTHS[i])) {
                sb.append(i + 1 < 10 ? "0" : "").append(i + 1).append('-');
                break;
            }
        }
        String day = split[0].substring(0, split[0].length() - 2);
        sb.append(day.length() < 2 ? "0" : "").append(day);
        return sb.toString();
    }
}