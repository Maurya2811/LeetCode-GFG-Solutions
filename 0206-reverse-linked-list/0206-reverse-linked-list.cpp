// 1. 
 // /*  Iteratively  
  
class Solution {
public:
    ListNode* reverseIterative(ListNode* &head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forward=head;
        
        while(curr){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
  // 2.  
    // /* Recursive
    ListNode* reverseRecursive(ListNode* &prev, ListNode* &curr){
        if(!curr){
            return prev;
        }
        ListNode* forward=curr->next;
        curr->next=prev;
        
     return  reverseRecursive(curr,forward);
    }
    
    
    
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        // head = reverseIterative(head);
        
        ListNode* prev=NULL;
        ListNode* curr=head;
          head = reverseRecursive(prev,curr);
        return head;
    }
};