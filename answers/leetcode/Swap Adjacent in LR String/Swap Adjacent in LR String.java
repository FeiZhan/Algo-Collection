class Solution {
    public boolean canTransform(String start, String end) {
        int index0 = 0;
        int index1 = 0;
        while (true) {
            while (index0 < start.length() && start.charAt(index0) == 'X') {
                index0++;
            }
            while (index1 < end.length() && end.charAt(index1) == 'X') {
                index1++;
            }
            if (index0 < start.length() && index1 < end.length()) {
                char c0 = start.charAt(index0);
                char c1 = end.charAt(index1);
                //System.out.println(index0 + " " + index1);
                if (c0 != c1) {
                    return false;
                } else if (c0 == 'L' && index0 < index1) {
                    return false;
                } else if (c0 == 'R' && index0 > index1) {
                    return false;
                } else {
                    index0++;
                    index1++;
                }
            } else {
                break;
            }
        }
        return index0 == start.length() && index1 == end.length();
    }
}