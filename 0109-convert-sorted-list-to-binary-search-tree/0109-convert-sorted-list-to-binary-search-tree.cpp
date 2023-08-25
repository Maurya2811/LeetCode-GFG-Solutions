
class Solution {
public:
    
   TreeNode* makeBST(ListNode* start, ListNode* end){
       if(start == end){
           return NULL;
       }
        
       ListNode* slow = start;
       ListNode* fast = start;
       
       while(fast!=end && fast->next!=end){
           slow=slow->next;
           fast = fast->next->next;
       }
       
       TreeNode* root = new TreeNode(slow->val);
       
       root->left = makeBST(start, slow); 
       root->right = makeBST(slow->next, end);
       
       return root;

   }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
            return NULL;
        
        
     return makeBST(head,NULL);
    
    }
};