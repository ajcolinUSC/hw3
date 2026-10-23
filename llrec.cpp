#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
  if (head == NULL) {
    smaller = NULL;
    larger = NULL;
    return;
  }
  Node *cur = head;
  head = head->next;
  llpivot(head, smaller, larger, pivot);
  if (cur->val <= pivot) {
    cur->next = smaller;
    smaller = cur;
  } else {
    cur->next = larger;
    larger = cur;
  }
  head = NULL;
}
