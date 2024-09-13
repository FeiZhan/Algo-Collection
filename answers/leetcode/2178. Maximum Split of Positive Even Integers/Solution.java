class Solution {
    public List<Long> maximumEvenSplit(long finalSum) {
        List<Long> result = new LinkedList<>();
        if (finalSum % 2 == 1) {
            return result;
        }

        for (long i = 2l; i <= finalSum; i += 2l) {
            result.add(i);
            finalSum -= i;
        }
        result.set(result.size() - 1, result.getLast() + finalSum);

        return result;
    }
}