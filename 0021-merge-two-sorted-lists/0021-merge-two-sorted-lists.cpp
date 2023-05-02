class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
           
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        
        ListNode* ans= new ListNode(-1);
         ListNode* ansPtr= ans;
       while(list1 && list2) {
        if(list1->val<=list2->val){
            ansPtr->next=list1;
            list1=list1->next;
            ansPtr= ansPtr->next;
            ansPtr->next=NULL;
        }
        else{
            ansPtr->next=list2;
            list2=list2->next;
            ansPtr= ansPtr->next;
            ansPtr->next=NULL;
        }
       } 
    
    if(list1){
        ansPtr->next=list1;
    }
    if(list2){
        ansPtr->next=list2;
    }
    return ans->next;
    }
};