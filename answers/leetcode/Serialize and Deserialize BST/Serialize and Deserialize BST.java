/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        List<Integer> values = new ArrayList<>();
        this.preorder(root, values);
        return values.stream()
            .map(i -> i.toString())
            .collect(Collectors.joining(","));
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (null == data || 0 == data.length()) {
            return null;
        }
        int[] values = Arrays.stream(data.split(","))
            .mapToInt(Integer::parseInt)
            .toArray();
        return this.preorder(values, 0, values.length - 1);
    }
    
    private void preorder(TreeNode root, List<Integer> values) {
        if (null == root) {
            return;
        }
        values.add(root.val);
        this.preorder(root.left, values);
        this.preorder(root.right, values);
    }
    
    private TreeNode preorder(int[] values, int start, int end) {
        if (start > end) {
            return null;
        }
        TreeNode root = new TreeNode(values[start]);
        int right;
        for (right =  start; right <= end && values[right] <= values[start]; right++) {}
        root.left = this.preorder(values, start + 1, right - 1);
        root.right = this.preorder(values, right, end);
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));