/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return head;
        }
        Node* tempHead = head;
        
      while(tempHead){
          Node* fwd = tempHead->next;
          tempHead->next = new Node(tempHead->val);
          tempHead->next->next = fwd;
          
          tempHead = fwd;
      }
        
        // Handling Random
        tempHead = head;
       

        
        while(tempHead){
            if(tempHead->random)
            tempHead->next->random = tempHead->random->next;
            
            if(tempHead->next){
                tempHead = tempHead->next->next;
            }
            
        }
        
         Node* currHead = head->next;
        Node* currNode = currHead;
        
         tempHead = head;
        
        while(tempHead){
            
            if(tempHead->next){
                tempHead->next=tempHead->next->next;
            }
            
            if(currNode->next){
                currNode->next = currNode->next->next;
            }
            
            
            tempHead = tempHead->next;
            currNode = currNode->next;
            
        }
        
        
        
        return currHead;
    }
};