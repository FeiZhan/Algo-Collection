bool deleteNode(LinkedListNode n) {
	if (NULL == n || NULL == n.next) {
		return false;
	}
	LinkedListNode next = n.next;
	n.data = next.data;
	n.next = next.next;
	return true;
}