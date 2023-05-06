
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || !head->next)
            return head;
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
            
        }
        return slow;
    }
};