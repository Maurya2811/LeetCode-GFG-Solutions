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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int count=0;
       ListNode* temp =head;
         ListNode* fwd =NULL;
        
        while(temp){
            count++;
            temp=temp->next;
        }
        
        // int parts = ;
        int extraNodes = count%k;
        int node = count/k;
        
        vector<ListNode*> ans(k,NULL);
        int i=0;
        temp = head;
        ListNode* prev = NULL;
        // cout<<count<<" "<<parts;
       
        while(temp){
            int x=node;
            while(temp && x){
                   prev= temp;
                    temp=temp->next;
                    x--;
                } 
                if(extraNodes){
                 if(temp){
                     prev= temp;
                     temp=temp->next;
                     extraNodes--;
                  }       
               }
          prev->next=NULL;
            ans[i++]=head; 
            head=temp;
            
        }
    //     while(extraNodes){
    //              if(temp){
    //                  prev= temp;
    //                  temp=temp->next;
    //                  extraNodes--;
    //               }       
    //       prev->next=NULL;
    //         ans[i++]=head; 
    //         head=temp;
    // }
        return ans;
    }
};