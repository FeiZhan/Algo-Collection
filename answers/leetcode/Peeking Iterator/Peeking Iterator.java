// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html
class PeekingIterator implements Iterator<Integer> {
    
    private Integer nextInt;
    private Iterator<Integer> iterator;

	public PeekingIterator(Iterator<Integer> iterator) {
	    // initialize any member here.
	    this.iterator = iterator;
        this.nextInt = null;
        this.next();
	}

    // Returns the next element in the iteration without advancing the iterator.
	public Integer peek() {
        return this.nextInt;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	@Override
	public Integer next() {
	    Integer result = this.nextInt;
        this.nextInt = this.iterator.hasNext() ? this.iterator.next() : null;
        return result;
	}

	@Override
	public boolean hasNext() {
	    return this.nextInt != null;
	}
}