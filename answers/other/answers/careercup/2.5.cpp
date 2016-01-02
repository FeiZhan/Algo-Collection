LinkedListNode findBeginning(LinkedListNode head) {
	LinkedListNode n1 = head;
	LinkedListNode n2 = head;
	while (n2.next) {
		n1 = n1.next;
		n2 = n2.next.next;
		if (n1 == n2) {
			break;
		}
	}
	if (NULL == n2.next) {
		return NULL;
	}
	n1 = head;
	while (n1 != n2) {
		n1 = n1.next;
		n2 = n2.next;
	}
	return n2;
}