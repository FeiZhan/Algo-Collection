import java.util.SortedMap;
import java.util.SortedSet;

/*
 * @lc app=leetcode id=987 lang=java
 *
 * [987] Vertical Order Traversal of a Binary Tree
 */
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
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        SortedMap<Integer, SortedMap<Integer, SortedSet<Integer>>> map = new TreeMap<>();
        this.dfs(0, 0, root, map);
        List<List<Integer>> result = new LinkedList<>();
        for (int x : map.keySet()) {
            SortedMap<Integer, SortedSet<Integer>> temp = map.get(x);
            List<Integer> list = new LinkedList<>();
            for (int y : temp.keySet()) {
                list.addAll(temp.get(y));
            }
            result.add(list);
        }
        return result;
    }

    private void dfs(int x, int y, TreeNode root, SortedMap<Integer, SortedMap<Integer, SortedSet<Integer>>> map) {
        if (root == null) {
            return;
        }
        SortedMap<Integer, SortedSet<Integer>> temp = map.getOrDefault(x, new TreeMap<>(Collections.reverseOrder()));
        SortedSet<Integer> set = temp.getOrDefault(y, new TreeSet<>());
        set.add(root.val);
        temp.put(y, set);
        map.put(x, temp);
        this.dfs(x - 1, y - 1, root.left, map);
        this.dfs(x + 1, y - 1, root.right, map);
    }
}

