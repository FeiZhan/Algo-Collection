import java.util.Map;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int numComponents(ListNode head, int[] G) {
        Map<Integer, Integer> connections = new HashMap<>();
        ListNode current = head;
        while (current != null && current.next != null) {
            connections.put(current.val, current.next.val);
            current = current.next;
        }
        Map<Integer, Integer> rootMap = new HashMap<>();
        Map<Integer, Set<Integer>> setMap = new HashMap<>();
        for (int node : G) {
            rootMap.put(node, node);
            Set<Integer> set = new HashSet<>();
            set.add(node);
            setMap.put(node, set);
        }
        for (int node : rootMap.keySet()) {
            if (connections.containsKey(node)) {
                int next = connections.get(node);
                if (rootMap.containsKey(next)) {
                    int root = rootMap.get(next);
                    int oldRoot = rootMap.get(node);
                    Set<Integer> oldSet = setMap.get(oldRoot);
                    for (int oldNode : oldSet) {
                        rootMap.put(oldNode, root);
                    }
                    setMap.get(root).addAll(oldSet);
                    setMap.remove(oldRoot);
                }
            }
        }
        return setMap.size();
    }
}