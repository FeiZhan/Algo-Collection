class Solution {
    public List<String> alertNames(String[] keyName, String[] keyTime) {
        int length = keyName.length;
        Map<String, List<Integer>> nameMap = new HashMap<>();
        for (int i = 0; i < length; i++) {
            int hour = Integer.parseInt(keyTime[i].substring(0, 2));
            int time = hour * 60 + Integer.parseInt(keyTime[i].substring(3));
            List<Integer> list = nameMap.getOrDefault(keyName[i], new ArrayList<>());
            list.add(time);
            nameMap.put(keyName[i], list);
        }

        List<String> result = new LinkedList<>();
        for (String name : nameMap.keySet()) {
            List<Integer> list = nameMap.get(name);
            Collections.sort(list);
            int left = 0;
            for (int i = 0; i < list.size(); i++) {
                while (list.get(i) - list.get(left) > 60) {
                    left++;
                }
                if (i - left >= 2) {
                    result.add(name);
                    break;
                }
            }
        }

        Collections.sort(result);
        return result;
    }
}