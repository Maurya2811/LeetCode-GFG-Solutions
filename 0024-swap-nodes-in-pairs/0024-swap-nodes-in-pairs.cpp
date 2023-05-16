/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || !head->next)
            return head;
        ListNode* temp=head;
        ListNode* fwd = head;
        head=head->next;
        
        
        while(temp && temp->next!=NULL){
            temp=temp->next->next;
            fwd->next->next=fwd;
        if(temp) {
            if(temp->next) {
                fwd->next=temp->next;
                fwd=temp;
            }else{
                fwd->next=temp;;
            }
        }else{
            fwd->next=NULL;
        }
        }
        return head;
    }
};