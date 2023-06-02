class Solution {
    public int buyChoco(int[] prices, int money) {
        List<Integer> mins = new ArrayList<>();
        mins.add(100_000);
        mins.add(100_000);

        for (int price : prices) {
            if (price < mins.get(1)) {
                mins.remove(1);
                if (price < mins.get(0)) {
                    mins.add(0, price);
                } else {
                    mins.add(price);
                }
            }
        }

        int remain = money - mins.get(0) - mins.get(1);
        return remain >= 0 ? remain : money;
    }
}