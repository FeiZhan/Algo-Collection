class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int result = 0;
        for (String operation : operations) {
            result += operation.indexOf('+') >= 0 ? 1 : -1;
        }

        return result;
    }
}