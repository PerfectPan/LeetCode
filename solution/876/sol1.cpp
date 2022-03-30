/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int cnt=0,tot=0;
        ListNode* t=head;
        for (;head!=NULL;head=head->next){
            cnt++;
        }
        tot=cnt/2+1;
        cnt=0;
        for (head=t;head!=NULL;head=head->next){
            cnt++;
            if (cnt==tot) return head;
        }
        return NULL;
    }
};

