class Solution {
    public List<Integer> pathInZigZagTree(int label) {
        int firstInLevel = 1;
        int temp = label;
        while (temp > 1) {
            temp /= 2;
            firstInLevel *= 2;
        }
        int mirror = 0;
        if (label < firstInLevel * 1.5) {
            mirror = firstInLevel * 2 - (label - firstInLevel) - 1;
        } else {
            mirror = firstInLevel + (firstInLevel * 2 - label - 1);
        }
        boolean flag = false;
        List<Integer> path = new LinkedList<>();
        path.add(label);
        while (label > 1) {
            label /= 2;
            mirror /= 2;
            path.add(flag ? label : mirror);
            flag = !flag;
        }
        Collections.reverse(path);
        return path;
    }
}