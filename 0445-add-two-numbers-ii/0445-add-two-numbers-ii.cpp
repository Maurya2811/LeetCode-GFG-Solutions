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
    
     ListNode* reverseLL(ListNode* head) {
        
        if(!head || !head->next) {
            return head;
        }
        
        ListNode* last = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
        
    }
    ListNode* add(ListNode* ll1, ListNode* ll2){
        int sum=0;
        ListNode* ans=NULL;
        int carry=0;
        
        while(ll1 ||  ll2){
            if(ll1){
                sum += ll1->val;
                ll1=ll1->next;
            }
             if(ll2){
                sum += ll2->val;
                ll2=ll2->next;
            }
            
            carry=sum/10;
            cout<<carry << " "<< sum <<endl;
            sum=sum%10;
            cout<<carry << " "<< sum <<endl;
            ListNode* newNode = new ListNode(sum,ans);
            ans=newNode;
            
            sum=carry;
            
        }
        while(carry) {
            ListNode* newNode = new ListNode(carry,ans);
             ans=newNode;
            carry/=10;
        }
        return ans;
    }
    // void print(ListNode* head){
    //     while(head){
    //         cout<<head->val<<"->";
    //         head=head->next;
    //     }
    // }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
         ListNode *   l1_head   =  reverseLL(l1);
         ListNode *    l2_head   =  reverseLL(l2);
        // print(l1_head);
        // print(l2_head);
        
        return add(l1_head,l2_head);

    }
};