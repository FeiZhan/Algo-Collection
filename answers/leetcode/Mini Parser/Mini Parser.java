/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
class Solution {
    public NestedInteger deserialize(String s) {
        NestedInteger current = null;
        Stack<NestedInteger> stack = new Stack<>();
        boolean negative = false;
        for (char c : s.toCharArray()) {
            switch (c) {
                case '[':
                    if (current == null) {
                        current = new NestedInteger();
                    }
                    negative = false;
                    stack.push(current);
                    current = null;
                    break;
                case ']':
                    negative = false;
                    NestedInteger parent = stack.pop();
                    if (current != null) {
                        parent.add(current);
                    }
                    current = parent;
                    break;
                case ',':
                    if (current == null) {
                        current = new NestedInteger();
                    }
                    negative = false;
                    stack.peek().add(current);
                    current = null;
                    break;
                case '-':
                    negative = true;
                    break;
                default:
                    if (current == null) {
                        current = new NestedInteger(0);
                    }
                    int number = current.getInteger() * 10 + Character.getNumericValue(c) * (negative ? -1 : 1);
                    current.setInteger(number);
            }
        }
        return current;
    }
}