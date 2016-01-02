LinkedListNode nthToLast(LinkedListNode head, int n) {
	if (NULL == head || n < 1) {
		return NULL;
	}
	LinkedListNode p1 = head;
	LinkedListNode p2 = head;
	for (int j = 0; j < n - 1; ++ j) {
		if (NULL == p2) {
			return NULL;
		}
		p2 = p2.next;
	}
	while (p2.next) {
		p1 = p1.next;
		p2 = p2.next;
	}
	return p1;
}