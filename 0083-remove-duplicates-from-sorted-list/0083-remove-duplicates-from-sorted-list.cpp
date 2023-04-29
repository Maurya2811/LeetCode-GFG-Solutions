
class Solution {
public:
    void removeDuplicates(ListNode* curr){
        while(curr->next!=NULL)
       { 
            if(curr->val==curr->next->val){
            ListNode* temp=curr->next;
            curr->next=curr->next->next;
            temp->next=NULL;
            delete temp;
        }
            else
                curr=curr->next;
       }
    }
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL){
            return head;
        }
        ListNode* curr=head;
         removeDuplicates(curr);
             return head;
    }
};
