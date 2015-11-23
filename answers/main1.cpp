/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* SortedInsert(Node *head,int data)
{
    // Complete this function
   // Do not write the main method. 
  if (head) {
    if (data <= head->data) {
      Node *current = new Node();
      current->data = data;
      current->next = head;
      current->prev = NULL;
      head->prev = current;
      head = current;
    }
    else {
      head->next = SortedInsert(head->next, data);
      if (head->next) {
        head->next->prev = head;
      }
    }
  }
  else {
    head = new Node();
    head->data = data;
    head->next = head->prev = NULL;
  }
  return head;
}
