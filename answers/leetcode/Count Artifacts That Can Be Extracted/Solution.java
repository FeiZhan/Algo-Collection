class Solution {
    public int digArtifacts(int n, int[][] artifacts, int[][] dig) {
        Set<Integer> digs = new HashSet<>();
        for (int[] d : dig) {
            digs.add(d[0] * 1000 + d[1]);
        }

        int result = 0;
        for (int[] artifact : artifacts) {
            boolean flag = true;
            for (int i = artifact[0]; i <= artifact[2]; i++) {
                for (int j = artifact[1]; j <= artifact[3]; j++) {
                    if (!digs.contains(i * 1000 + j)) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) {
                    break;
                }
            }
            if (flag) {
                result++;
            }
        }

        return result;
    }
}
//Runtime: 16 ms, faster than 55.66% of Java online submissions for Count Artifacts That Can Be Extracted.
//Memory Usage: 122.1 MB, less than 89.89% of Java online submissions for Count Artifacts That Can Be Extracted.
