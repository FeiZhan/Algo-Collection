class Solution {
    public int getNumberOfBacklogOrders(int[][] orders) {
        Map<Integer, Integer> buyMap = new HashMap<>();
        Map<Integer, Integer> sellMap = new HashMap<>();
        PriorityQueue<Integer> buyQueue = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> sellQueue = new PriorityQueue<>();
        for (int[] order : orders) {
            if (order[2] == 0) {
                buyMap.put(order[0], buyMap.getOrDefault(order[0], 0) + order[1]);
                buyQueue.add(order[0]);
            } else {
                sellMap.put(order[0], sellMap.getOrDefault(order[0], 0) + order[1]);
                sellQueue.add(order[0]);
            }
            while (!buyQueue.isEmpty() && !sellQueue.isEmpty() && buyQueue.peek() >= sellQueue.peek()) {
                int buy = buyQueue.peek();
                int sell = sellQueue.peek();
                int minOrder = Math.min(buyMap.get(buy), sellMap.get(sell));
                buyMap.put(buy, buyMap.get(buy) - minOrder);
                if (buyMap.get(buy) <= 0) {
                    buyMap.remove(buy);
                    buyQueue.poll();
                }
                sellMap.put(sell, sellMap.get(sell) - minOrder);
                if (sellMap.get(sell) <= 0) {
                    sellMap.remove(sell);
                    sellQueue.poll();
                }
            }
        }

        int result = 0;
        for (int count : buyMap.values()) {
            result = (result + count) % 1000000007;
        }
        for (int count : sellMap.values()) {
            result = (result + count) % 1000000007;
        }

        return result;
    }
}