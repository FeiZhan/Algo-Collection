import java.util.*;

class TaskManager {

    private Map<Integer, Integer> taskUserMap = new HashMap<>();
    private Map<Integer, Integer> taskPriorityMap = new HashMap<>();
    private SortedMap<Integer, SortedSet<Integer>> priorityMap = new TreeMap<>(Collections.reverseOrder());

    public TaskManager(List<List<Integer>> tasks) {
        for (List<Integer> task : tasks) {
            add(task.get(0), task.get(1), task.get(2));
        }
    }

    public void add(int userId, int taskId, int priority) {
        taskUserMap.put(taskId, userId);
        setPriority(taskId, priority);
    }

    public void edit(int taskId, int newPriority) {
        removePriority(taskId);
        setPriority(taskId, newPriority);
    }

    public void rmv(int taskId) {
        taskUserMap.remove(taskId);
        removePriority(taskId);
    }

    public int execTop() {
        if (!priorityMap.isEmpty()) {
            SortedSet<Integer> set = priorityMap.get(priorityMap.firstKey());
            if (!set.isEmpty()) {
                int taskId = set.iterator().next();
                int userId = taskUserMap.get(taskId);
                rmv(taskId);
                return userId;
            }
        }
        return -1;
    }

    private void setPriority(int taskId, int priority) {
        taskPriorityMap.put(taskId, priority);
        SortedSet<Integer> set = priorityMap.getOrDefault(priority, new TreeSet<>(Collections.reverseOrder()));
        set.add(taskId);
        priorityMap.put(priority, set);
    }

    private void removePriority(int taskId) {
        int priority = taskPriorityMap.remove(taskId);
        SortedSet<Integer> set = priorityMap.get(priority);
        set.remove(taskId);
        if (set.isEmpty()) {
            priorityMap.remove(priority);
        }
    }
}

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager obj = new TaskManager(tasks);
 * obj.add(userId,taskId,priority);
 * obj.edit(taskId,newPriority);
 * obj.rmv(taskId);
 * int param_4 = obj.execTop();
 */