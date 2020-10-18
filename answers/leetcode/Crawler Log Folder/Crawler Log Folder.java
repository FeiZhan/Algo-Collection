class Solution {
    public int minOperations(String[] logs) {
        int count = 0;
        for (String folder : logs) {
            if (folder.equals("./")) {
            } else if (folder.equals("../")) {
                if (count > 0) {
                    count--;
                }
            } else {
                count++;
            }
        }
        return count;
    }
}