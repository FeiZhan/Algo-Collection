class Solution {
    public List<Integer> filterRestaurants(int[][] restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        return Arrays
            .stream(restaurants)
            .filter(r -> r[2] >= veganFriendly && r[3] <= maxPrice && r[4] <= maxDistance)
            .sorted((r1, r2) -> r1[1] != r2[1] ? r2[1] - r1[1] : r2[0] - r1[0])
            .map(r -> r[0])
            .collect(Collectors.toList());
    }
}