/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {

    private List<ListNode> nodes;
    private Random random;

    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    public Solution(ListNode head) {
        this.random = new Random();
        this.nodes = new ArrayList<>();
        while (head != null) {
            this.nodes.add(head);
            head = head.next;
        }
    }
    
    /** Returns a random node's value. */
    public int getRandom() {
        int index = this.random.nextInt(this.nodes.size());
        return this.nodes.get(index).val;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */