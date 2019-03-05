class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        Map<Character, Integer> orders = new HashMap<>();
        for (int i = 0; i < order.length(); i++) {
            orders.put(order.charAt(i), i);
        }
        for (int i = 1; i < words.length; i++) {
            boolean same = true;
            for (int j = 0; j < words[i - 1].length() && j < words[i].length(); j++) {
                char c0 = words[i - 1].charAt(j);
                char c1 = words[i].charAt(j);
                if (c0 != c1) {
                    if (orders.get(c0) > orders.get(c1)) {
                        return false;
                    } else {
                        same = false;
                        break;
                    }
                }
            }
            if (same && words[i - 1].length() > words[i].length()) {
                return false;
            }
        }
        return true;
    }
}