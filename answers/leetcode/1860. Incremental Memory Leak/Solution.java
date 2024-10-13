class Solution {
    public int[] memLeak(int memory1, int memory2) {
        int time = 1;
        while (true) {
            if (memory1 >= memory2 && memory1 >= time) {
                memory1 -= time;
            } else if (memory1 < memory2 && memory2 >= time) {
                memory2 -= time;
            } else {
                break;
            }
            time++;
        }

        return new int[]{time, memory1, memory2};
    }
}