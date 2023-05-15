
// class Solution {
// public:
//     ListNode* swapNodes(ListNode* head, int k) {
//         ListNode* temp=head;
//         ListNode* firstNode=head;
//         ListNode* secondNode=head;
        
//         if(head->next==NULL)
//             return head;
        
//         int length=1;
        
//         while(temp->next!=NULL){
//             if(length==k){
//                 firstNode = temp;
//             }
            
//             if(length>=k){
//                 secondNode = secondNode->next;
//             }
//             length++;
            
//             temp=temp->next;
//         }
        
        
//         if(length==k){
//             firstNode=head;
//             secondNode=temp;
//         }
        
//         // swap(firstNode->val,secondNode->val);
//         int t=firstNode->val;
//         firstNode->val = secondNode->val;
//         secondNode->val=t;
        
//         return head;
//     }
// };

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
         ListNode* p1=NULL;
        ListNode* p2=NULL;
        ListNode* temp=head;
        while(temp){
            
            if(p2){
                p2=p2->next;
            }
            
           --k;
            if(k==0){
                p1=temp;
                p2=head; // Activate
            }
            
            temp=temp->next;
            
        }
        // swap(p1->val,p2->val);
        int t=p1->val;
        p1->val = p2->val;
        p2->val=t;
        return head;
    }
};