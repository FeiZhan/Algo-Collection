class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int length = A.length;
        int[] result = new int[length];
        Map<Integer, Integer> aMap = new HashMap<>();
        Map<Integer, Integer> bMap = new HashMap<>();

        for (int i = 0; i < length; i++) {
            result[i] = i > 0 ? result[i - 1] : 0;
            int aNumber = A[i];
            int bNumber = B[i];
            if (aNumber == bNumber) {
                result[i]++;
            } else {
                if (bMap.containsKey(aNumber)) {
                    result[i]++;
                    bMap.put(aNumber, bMap.get(aNumber) - 1);
                    if (bMap.get(aNumber) == 0) {
                        bMap.remove(aNumber);
                    }
                } else {
                    aMap.put(aNumber, aMap.getOrDefault(aNumber, 0) + 1);
                }
                if (aMap.containsKey(bNumber)) {
                    result[i]++;
                    aMap.put(bNumber, aMap.get(bNumber) - 1);
                    if (aMap.get(bNumber) == 0) {
                        aMap.remove(bNumber);
                    }
                } else {
                    bMap.put(bNumber, bMap.getOrDefault(bNumber, 0) + 1);
                }
            }
        }

        return result;
    }
}