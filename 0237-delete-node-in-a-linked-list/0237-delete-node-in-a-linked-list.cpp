// Simply copy the next node value and delete the next node

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        
        node->val = node->next->val;
        node->next = node->next->next;
        
        delete temp;
    }
};