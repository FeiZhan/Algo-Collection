/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode recoverFromPreorder(String S) {
        int count = 0;
        int value = 0;
        Map<Integer, TreeNode> nodes = new HashMap<>();
        for (int i = 0; i < S.length(); i++) {
            char c = S.charAt(i);
            if (c == '-') {
                count++;
            } else {
                int digit = Character.getNumericValue(c);
                value = value * 10 + digit;
            }
            if (i + 1 == S.length() || (c != '-' && S.charAt(i + 1) == '-')) {
                TreeNode node = new TreeNode(value);
                if (nodes.containsKey(count - 1)) {
                    TreeNode parent = nodes.get(count - 1);
                    if (parent.left == null) {
                        parent.left = node;
                    } else {
                        parent.right = node;
                    }
                }
                nodes.put(count, node);
                count = 0;
                value = 0;
            }
        }
        return nodes.getOrDefault(0, null);
    }
}