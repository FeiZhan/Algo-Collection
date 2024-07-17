class Solution {
    public int distributeCookies(int[] cookies, int k) {
        return dfs(0, new int[k], cookies);
    }

    private int dfs(int index, int[] kids, int[] cookies) {
        if (index == cookies.length) {
            int result = 0;
            for (int kid : kids) {
                result = Math.max(result, kid);
            }
            return result;
        }

        int cookie = cookies[index];
        int result = Integer.MAX_VALUE;
        for (int i = 0; i < kids.length; i++) {
            kids[i] += cookie;
            int maxKid = dfs(index + 1, kids, cookies);
            result = Math.min(result, maxKid);
            kids[i] -= cookie;
        }

        return result;
    }
}