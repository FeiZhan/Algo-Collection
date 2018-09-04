class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> addresses = new LinkedList<>();
        this.dfs(0, 0, new StringBuilder(), addresses, s);
        return addresses;
    }
    
    private void dfs(int index, int count, StringBuilder sb, List<String> addresses, String s) {
        if (index >= s.length() || count >= 4) {
            if (index >= s.length() && count == 4) {
                addresses.add(sb.toString());
            }
            return;
        }
        if (count > 0) {
            sb.append(".");
        }
        for (int i = index; i <= index + 2 && i < s.length(); i++) {
            int number = Integer.parseInt(s.substring(index, i + 1));
            if (number <= 255 && !(s.charAt(index) == '0' && i > index)) {
                StringBuilder sb1 = new StringBuilder(sb);
                sb1.append(number);
                this.dfs(i + 1, count + 1, sb1, addresses, s);
            }
        }
    }
}