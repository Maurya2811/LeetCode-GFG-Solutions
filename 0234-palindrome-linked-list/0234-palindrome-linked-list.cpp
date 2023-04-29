
class Solution {
public:
    
   ListNode* findMiddle (ListNode* &head){
       ListNode* slow=head;
       // ListNode* fast=head;
       ListNode* fast=head->next;
       
//        while(fast!=NULL && fast->next!=NULL){
           
//             fast=fast->next->next;
//             slow=slow->next;
           
//        }
       while(fast!=NULL){
           fast=fast->next;
           if(fast!=NULL){
              fast=fast->next; 
               slow=slow->next;
           }
       }
       return slow;
   }
    
   ListNode* reverseLL(ListNode* &prev,ListNode* &curr){
     
       if(curr==NULL)
           return prev;
       
      ListNode* temp=curr->next;
       curr->next=prev;
       
     return reverseLL(curr,temp);
   }
    
   bool checkPalindrome(ListNode* &head, ListNode* &MiddleHead){
       ListNode* left=head;
       while(MiddleHead!=NULL){
           if(left->val != MiddleHead->val)
               return false;
           left=left->next;
           MiddleHead=MiddleHead->next;
       }
       return true;
   }
    
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL)
            return false;
        if(head->next==NULL)
            return true;
        
        ListNode* middle = findMiddle(head);
        
        ListNode* prev=NULL;
        ListNode* curr=middle->next;
      ListNode* MiddleHead = reverseLL (prev,curr);
        
        return checkPalindrome( head,MiddleHead);
    }
};