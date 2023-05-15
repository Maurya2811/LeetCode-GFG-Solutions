
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* firstNode;
        ListNode* secondNode=head;
        
        
        int length=0;
        
        while(temp!=NULL){
            if(length+1==k){
                firstNode = temp;
            }
            length++;
            temp=temp->next;
        }
        int count = length-k;
        while(count){
            secondNode = secondNode->next;
            count--;
        }
        
        // swap(firstNode->val,secondNode->val);
        int t=firstNode->val;
        firstNode->val = secondNode->val;
        secondNode->val=t;
        return head;
    }
};