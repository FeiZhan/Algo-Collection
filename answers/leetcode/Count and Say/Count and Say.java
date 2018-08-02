class Solution {

    private Map<Integer, String> map = new HashMap<>();

    public String countAndSay(int n) {
        if (!this.map.containsKey(n)) {
            StringBuilder sb = new StringBuilder();
            if (n == 1) {
                sb.append("1");
            } else {
                String previous = this.countAndSay(n - 1);
                int left = 0;
                int right = 0;
                while (right <= previous.length()) {
                    if (right == previous.length() || previous.charAt(left) != previous.charAt(right)) {
                        sb.append(right - left);
                        sb.append(previous.charAt(left));
                        left = right;
                    }
                    right++;
                }
            }
            this.map.put(n, sb.toString());
        }
        return this.map.get(n);
    }
}