// Khud se Kiya hua
/*
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
             }else
                   fwd->next=temp;;
          }else
              fwd->next=NULL;
        }   
        return head;
    }
};
*/

// Recursive Solution
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || !head->next)
            return head;
       
        ListNode* temp= head->next;
        head->next=swapPairs(head->next->next);
        temp->next=head;
        return temp;
    }
};