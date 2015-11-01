//@type Design
//@result 12 / 12 test cases passed. Status: Accepted Runtime: 4 ms Submitted: 1 minute ago

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    head = 0;
		peeked = false;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (! peeked) {
			head = next();
			peeked = true;
		}
		return head;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        if (peeked) {
			peeked = false;
			return head;
		}
		else {
			return Iterator::next();
		}
	}

	bool hasNext() const {
        if (peeked) {
			return true;
		}
		else {
			return Iterator::hasNext();
		}
	}
	int head;
	bool peeked;
};