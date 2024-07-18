class Solution {
    public int[] executeInstructions(int n, int[] startPos, String s) {
        int length = s.length();
        int[] result = new int[length];
        for (int i = 0; i < length; i++) {
            result[i] = length - i;
            int[] position = new int[]{startPos[0], startPos[1]};
            for (int j = i; j < length; j++) {
                char c = s.charAt(j);
                switch (c) {
                    case 'L':
                        position[1]--;
                        break;
                    case 'R':
                        position[1]++;
                        break;
                    case 'U':
                        position[0]--;
                        break;
                    case 'D':
                        position[0]++;
                        break;
                }
                boolean flag = false;
                for (int pos : position) {
                    if (pos < 0 || pos >= n) {
                        flag = true;
                        break;
                    }
                }
                if (flag) {
                    result[i] = j - i;
                    break;
                }
            }
        }

        return result;
    }
}