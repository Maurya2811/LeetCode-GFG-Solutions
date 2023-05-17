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
    
     int findLen(ListNode* &head){
         ListNode* temp=head;
         int len=0;
         while(temp){
             len++;
             temp=temp->next;
         }
         return len;
     }
    int pairSum(ListNode* head) {
        int len= findLen(head);
        int n=len;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forward;
        // ListNode* slow=NULL;
        // ListNode* fast=head;
        int sum=0;
        while(n!=len/2){
            forward=curr->next;
            curr->next=prev;      
            prev=curr;
            curr=forward;       
            n--;
        }
        while(n){
       int temp= prev->val + forward->val;
            sum= max(sum,temp);
               prev=prev->next;
           
            forward=forward->next;
            n--;
            
        }
        return sum;
    }
};