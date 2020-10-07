class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode *temp = dummyHead;
    while (temp->next != nullptr && temp->next->next != nullptr) {
      ListNode *node1 = temp->next;
      ListNode *node2 = temp->next->next;
      temp->next = node2;
      node1->next = node2->next;
      node2->next = node1;
      temp = node1;
    }
    return dummyHead->next;
  }
};
