/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
  // Complete this method
  Node *dummy = new Node();
  dummy->data = -1;
  while (head) {
      Node *temp = head->next;
      head->next = dummy->next;
      dummy->next = head;
      head = temp;
  }
  return dummy->next;
}
