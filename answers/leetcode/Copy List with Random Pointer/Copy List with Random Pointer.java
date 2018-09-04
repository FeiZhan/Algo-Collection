/**
 * Definition for singly-linked list with a random pointer.
 * class RandomListNode {
 *     int label;
 *     RandomListNode next, random;
 *     RandomListNode(int x) { this.label = x; }
 * };
 */
public class Solution {
    public RandomListNode copyRandomList(RandomListNode head) {
        Map<RandomListNode, RandomListNode> nodeMap = new HashMap<>();
        RandomListNode dummy = new RandomListNode(-1);
        RandomListNode current = dummy;
        RandomListNode target = head;
        while (target != null) {
            current.next = new RandomListNode(target.label);
            current.next.next = null;
            current.next.random = null;
            nodeMap.put(target, current.next);
            current = current.next;
            target = target.next;
        }
        current = dummy.next;
        target = head;
        while (target != null) {
            if (target.random != null && nodeMap.containsKey(target.random)) {
                current.random = nodeMap.get(target.random);
            }
            current = current.next;
            target = target.next;
        }
        return dummy.next;
    }
}