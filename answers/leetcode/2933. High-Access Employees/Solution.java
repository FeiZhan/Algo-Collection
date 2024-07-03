class Solution {
    public List<String> findHighAccessEmployees(List<List<String>> access_times) {
        Map<String, List<Integer>> employeeMap = new HashMap<>();
        for (List<String> access : access_times) {
            String employee = access.get(0);
            String timeString = access.get(1);
            int time = Integer.parseInt(timeString.substring(0, 2)) * 60 + Integer.parseInt(timeString.substring(2));
            List<Integer> list = employeeMap.getOrDefault(employee, new ArrayList<>());
            list.add(time);
            employeeMap.put(employee, list);
        }

        List<String> result = new LinkedList<>();
        for (String employee : employeeMap.keySet()) {
            int left = 0;
            List<Integer> list = employeeMap.get(employee);
            Collections.sort(list);
            for (int i = 1; i < list.size(); i++) {
                int time = list.get(i);
                while (left <= i && time - list.get(left) >= 60) {
                    left++;
                }
                if (i - left >= 2 && time - list.get(left) < 60) {
                    result.add(employee);
                    break;
                }
            }
        }

        return result;
    }
}