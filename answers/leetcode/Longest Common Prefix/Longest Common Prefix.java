class Solution {
    public String longestCommonPrefix(String[] strs) {
        String result = "";
        if (strs != null && strs.length > 0) {
            result = strs[0];
            for (String str : strs) {
                while (str.indexOf(result) != 0) {
                    result = result.substring(0, result.length() - 1);
                }
            }
        }
        return result;
    }
}