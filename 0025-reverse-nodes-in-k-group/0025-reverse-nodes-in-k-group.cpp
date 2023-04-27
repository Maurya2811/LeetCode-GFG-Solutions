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
//    ListNode* reverseLL(ListNode* &prev,ListNode* &curr){
//        if(!curr){
//            return prev;
//        }
//       ListNode* forward=curr->next;
//       curr->next=prev;
//        return reverseLL(curr,forward);
       
//    }
    
    
//     ListNode* reverseKNode(ListNode* head, int k,ListNode* &prev,int &count){
       
//         while(count){
//             reverseLL(prev,head);
            
//         }
         
//         return prev;
//     }
    int findLen(ListNode* head){
        ListNode* temp= head;
        int len=0;
        while(temp){
            temp=temp->next;
            len++;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)
            return NULL;
        
        
        int len=findLen(head);
        
        if(k>len)
            return head;
        
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forward ;
        int count=0;
        while(count < k ){
            forward =curr->next;
              curr->next=prev;
              prev=curr;
              curr=forward;
    
            count++;
        }
             
      if(forward)
          head->next = reverseKGroup(forward,k);
        
        
        return prev;
        
    }
};