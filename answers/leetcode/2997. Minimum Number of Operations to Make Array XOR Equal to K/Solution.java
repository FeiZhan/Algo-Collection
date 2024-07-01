class Solution {
    public int minOperations(int[] nums, int k) {
        List<Boolean> targetBits = new ArrayList<>();
        while (k > 0) {
            targetBits.add(k % 2 == 1);
            k /= 2;
        }

        List<Boolean> xorBits = new ArrayList<>();
        for (int number : nums) {
            List<Boolean> bits = new ArrayList<>();
            while (number > 0) {
                bits.add(number % 2 == 1);
                number /= 2;
            }
            for (int i = 0; i < bits.size(); i++) {
                if (i < xorBits.size()) {
                    xorBits.set(i, xorBits.get(i) != bits.get(i));
                } else {
                    xorBits.add(bits.get(i));
                }
            }
        }

        int result = 0;
        for (int i = 0; i < targetBits.size() || i < xorBits.size(); i++) {
            if (i < targetBits.size() && i < xorBits.size()) {
                System.out.println(i + " " + targetBits.get(i) + " " + xorBits.get(i));
                result += targetBits.get(i) != xorBits.get(i) ? 1 : 0;
            } else if ((i < targetBits.size() && targetBits.get(i)) || (i < xorBits.size() && xorBits.get(i))) {
                result++;
            }
        }

        return result;
    }
}