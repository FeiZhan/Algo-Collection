class Solution {
    public List<String> buildArray(int[] target, int n) {
        int index = 0;
        List<String> result = new LinkedList<>();
        for (int i = 1; i <= n && index < target.length; i++) {
            result.add("Push");
            if (target[index] == i) {
                index++;
            } else {
                result.add("Pop");
            }
        }
        return result;
    }
}