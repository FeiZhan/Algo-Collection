void deleteDups(LinkListNode n) {
	Hashtable table;
	LinkListNode prev;
	while (n) {
		if (table.containsKey(n.data)) {
			prev.next = n.next;
		}
		else {
			table.insert(n.data, true);
			prev = n;
		}
		n = n.next;
	}
}
void deleteDups2(LinkListNode head) {
	if (NULL == head) {
		return;
	}
	LinkListNode prev = head;
	LinkListNode current = prev.next;
	while (current) {
		LinkListNode runner = head;
		while (runner != current) {
			if (runner.data == current.data) {
				LinkListNode temp = current.next;
				prev.next = temp;
				current = temp;
				break;
			}
			runner = runner.next;
		}
		if (runner == current) {
			prev = current;
			current = current.next;
		}
	}
}