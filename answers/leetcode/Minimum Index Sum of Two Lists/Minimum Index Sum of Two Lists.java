class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        Map<String, Integer> restaurants = new HashMap<String, Integer>();
        for (int i = 0; i < list1.length; i++) {
            restaurants.put(list1[i], i);
        }
        int minSum = Integer.MAX_VALUE;
        List<Integer> minIndices = new ArrayList<Integer>();
        for (int i = 0; i < list2.length; i++) {
            if (restaurants.containsKey(list2[i])) {
                int indices = i + restaurants.get(list2[i]);
                if (indices < minSum) {
                    minSum = indices;
                    minIndices = new ArrayList<Integer>();
                }
                if (indices == minSum) {
                    minIndices.add(i);
                }
            }
        }
        String[] result = new String[minIndices.size()];
        for (int i = 0; i < minIndices.size(); i++) {
            result[i] = list2[minIndices.get(i)];
        }
        return result;
    }
}