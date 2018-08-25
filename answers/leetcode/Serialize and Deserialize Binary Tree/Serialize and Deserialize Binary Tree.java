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
        StringBuilder sb = new StringBuilder();
        if (root != null) {
            sb.append(root.val)
                .append(",")
                .append(this.serialize(root.left))
                .append(",")
                .append(this.serialize(root.right));
        } else {
            sb.append("null");
        }
        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String[] splitted = data.split(",");
        this.index = 0;
        return this.deserialize(splitted);
    }
    
    private int index;
    
    private TreeNode deserialize(String[] splitted) {
        if (splitted == null || splitted.length == 0 || splitted[this.index].equals("null")) {
            this.index++;
            return null;
        }
        TreeNode root = new TreeNode(Integer.parseInt(splitted[this.index]));
        this.index++;
        root.left = this.deserialize(splitted);
        root.right = this.deserialize(splitted);
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));