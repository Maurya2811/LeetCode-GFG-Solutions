
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* firstNode=head;
        ListNode* secondNode=head;
        
        if(head->next==NULL)
            return head;
        
        int length=1;
        
        while(temp->next!=NULL){
            if(length==k){
                firstNode = temp;
            }
            
            if(length>=k){
                secondNode = secondNode->next;
            }
            length++;
            
            temp=temp->next;
        }
        
//        while(fast->next!=NULL){
//             slow=slow->next;
//             fast=fast->next;
            
//         }
        
        if(length==k){
            firstNode=head;
            secondNode=temp;
        }
        
        swap(firstNode->val,secondNode->val);
        // int t=firstNode->val;
        // firstNode->val = secondNode->val;
        // secondNode->val=t;
        
        return head;
    }
};
// class Solution {
// public:
//     ListNode* swapNodes(ListNode* head, int k) {
//          ListNode* slow=head;
//         ListNode* fast=head;
//          ListNode* f;
//         ListNode* l;
//         while(--k){
//             fast=fast->next;
//         }
//         f=fast;
//         while(fast->next!=NULL){
//             slow=slow->next;
//             fast=fast->next;
            
//         }
//         swap(slow->val,f->val);
//         return head;
//     }
// };