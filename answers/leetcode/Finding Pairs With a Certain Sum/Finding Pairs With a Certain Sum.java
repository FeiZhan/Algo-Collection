class FindSumPairs {

    private int[] numbers2;
    private Map<Integer, Integer> numberMap1;
    private Map<Integer, Integer> numberMap2;

    public FindSumPairs(int[] nums1, int[] nums2) {
        this.numbers2 = nums2;

        this.numberMap1 = new HashMap<>();
        for (int number : nums1) {
            this.numberMap1.put(number, this.numberMap1.getOrDefault(number, 0) + 1);
        }

        this.numberMap2 = new HashMap<>();
        for (int number : nums2) {
            this.numberMap2.put(number, this.numberMap2.getOrDefault(number, 0) + 1);
        }
    }

    public void add(int index, int val) {
        if (this.numberMap2.get(this.numbers2[index]) > 1) {
            this.numberMap2.put(this.numbers2[index], this.numberMap2.get(this.numbers2[index]) - 1);
        } else {
            this.numberMap2.remove(this.numbers2[index]);
        }
        this.numbers2[index] += val;
        this.numberMap2.put(this.numbers2[index], this.numberMap2.getOrDefault(this.numbers2[index], 0) + 1);
    }

    public int count(int tot) {
        int result = 0;
        for (int number1 : this.numberMap1.keySet()) {
            int count1 = this.numberMap1.get(number1);
            int number2 = tot - number1;
            if (this.numberMap2.containsKey(number2)) {
                result += count1 * this.numberMap2.get(number2);
            }
        }

        return result;
    }
}

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs obj = new FindSumPairs(nums1, nums2);
 * obj.add(index,val);
 * int param_2 = obj.count(tot);
 */