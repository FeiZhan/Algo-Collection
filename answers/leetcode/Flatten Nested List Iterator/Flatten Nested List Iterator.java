/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
public class NestedIterator implements Iterator<Integer> {

    private int index = 0;
    private List<Integer> list = new ArrayList<>();

    public NestedIterator(List<NestedInteger> nestedList) {
        for (NestedInteger value : nestedList) {
            this.add(value);
        }
    }

    @Override
    public Integer next() {
        return this.list.get(this.index++);
    }

    @Override
    public boolean hasNext() {
        return this.index < this.list.size();
    }

    private void add(NestedInteger nestedInteger) {
        if (nestedInteger.isInteger()) {
            this.list.add(nestedInteger.getInteger());
        } else {
            List<NestedInteger> nextList = nestedInteger.getList();
            for (NestedInteger value : nextList) {
                this.add(value);
            }
        }
    }
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.hasNext()) v[f()] = i.next();
 */