class Solution {
    public int shoppingOffers(List<Integer> price, List<List<Integer>> special, List<Integer> needs) {
        Map<List<Integer>, Integer> cache = new HashMap<>();
        List<Integer> emptyNeed = new ArrayList<>();
        for (int need : needs) {
            emptyNeed.add(0);
        }
        cache.put(emptyNeed, 0);
        int minPrice = this.dfs(needs, cache, price, special);
        return minPrice;
    }

    private int dfs(List<Integer> needs, Map<List<Integer>, Integer> cache, List<Integer> prices, List<List<Integer>> specials) {
        if (!cache.containsKey(needs)) {
            int minPrice = 0;
            for (int i = 0; i < prices.size(); i++) {
                minPrice += needs.get(i) * prices.get(i);
            }
            for (List<Integer> special : specials) {
                List<Integer> localNeeds = new ArrayList<>(needs);
                boolean valid = true;
                for (int i = 0; i + 1 < special.size(); i++) {
                    if (special.get(i) > localNeeds.get(i)) {
                        valid = false;
                        break;
                    }
                    localNeeds.set(i, localNeeds.get(i) - special.get(i));
                }
                if (valid) {
                    int price = this.dfs(localNeeds, cache, prices, specials);
                    if (price < Integer.MAX_VALUE && price >= 0) {
                        minPrice = Math.min(minPrice, price + special.get(special.size() - 1));
                    }
                }
            }
            cache.put(needs, minPrice);
        }
        return cache.get(needs);
    }
}