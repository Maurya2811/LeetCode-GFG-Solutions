// Slow and Fast Pointer Approach

class Solution {
public:
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *start= new ListNode();
        start->next=head;
        ListNode* fast=start;
        ListNode* slow=start;
        
        while(n>0){
            fast=fast->next;
            n--;
        }
        
        while( fast->next!=NULL){
             slow=slow->next;
            fast=fast->next;
           
        }
        
//         if(slow==head){
//             ListNode* temp=head;
//             head=head->next;
//             temp->next= NULL;
//             delete temp;
//             return head;
//         }
            
        ListNode* temp=slow->next;
        slow->next=slow->next->next;
        temp->next=NULL;
        delete temp;
        return start->next;
    }
};