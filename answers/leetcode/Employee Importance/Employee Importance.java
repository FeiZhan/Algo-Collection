/*
// Employee info
class Employee {
    // It's the unique id of each node;
    // unique id of this employee
    public int id;
    // the importance value of this employee
    public int importance;
    // the id of direct subordinates
    public List<Integer> subordinates;
};
*/
class Solution {
    Map<Integer, Integer> importance;
    
    public int getImportance(List<Employee> employees, int id) {
        importance = new HashMap<Integer, Integer>();
        Map<Integer, Employee> employeeMap = new HashMap<Integer, Employee>();
        for (Employee e : employees) {
            employeeMap.put(e.id, e);
        }
        return getImportance(employeeMap, id);
    }
    
    private int getImportance(Map<Integer, Employee> map, int id) {
        if (importance.containsKey(id)) {
            return importance.get(id);
        }
        if (map == null || !map.containsKey(id)) {
            return 0;
        }
        Employee e = map.get(id);
        int imp = e.importance;
        for (int sub : e.subordinates) {
            imp += getImportance(map, sub);
        }
        importance.put(id, imp);
        return imp;
    }
}