class Solution {

    private static Map<Integer, Integer> powers = new HashMap<>();

    static {
        powers.put(1, 0);
        for (int i = 1; i <= 1000; i++) {
            getPower(i);
        }
    }

    public int getKth(int lo, int hi, int k) {
        PriorityQueue<Integer> queue = new PriorityQueue<>((n0, n1) -> {
            int diff = getPower(n0) - getPower(n1);
            return diff != 0 ? diff : n0 - n1;
        });
        for (int i = lo; i <= hi; i++) {
            queue.add(i);
        }
        int number = -1;
        for (int i = 0; i < k; i++) {
            number = queue.poll();
            //System.out.println(i + " " + number + " " + powers.get(number));
        }
        return number;
    }

    static private int getPower(int number) {
        if (!powers.containsKey(number)) {
            powers.put(number, getPower(number % 2 == 0 ? number / 2 : number * 3 + 1) + 1);
        }
        return powers.get(number);
    }
}