import java.util.SortedMap;

class Solution {
    public List<List<String>> displayTable(List<List<String>> orders) {
        SortedMap<String, Integer> items = new TreeMap<>();
        SortedMap<Integer, Map<String, Integer>> table = new TreeMap<>();
        for (List<String> order : orders) {
            int number = Integer.parseInt(order.get(1));
            Map<String, Integer> map = table.getOrDefault(number, new HashMap<>());
            String food = order.get(2);
            items.put(food, 0);
            map.put(food, map.getOrDefault(food, 0) + 1);
            table.put(number, map);
        }
        int index = 0;
        for (String food : items.keySet()) {
            items.put(food, index);
            index++;
        }
        List<String> title = new LinkedList<>(items.keySet());
        title.add(0, "Table");
        List<List<String>> result = new LinkedList<>();
        result.add(title);
        for (int number : table.keySet()) {
            List<String> row = new ArrayList<>();
            row.add(Integer.toString(number));
            for (int i = 0; i < items.size(); i++) {
                row.add("0");
            }
            index = 1;
            Map<String, Integer> foods = table.get(number);
            for (String food : items.keySet()) {
                if (foods.containsKey(food)) {
                    row.set(index, Integer.toString(foods.get(food)));
                }
                index++;
            }
            result.add(row);
        }
        return result;
    }
}