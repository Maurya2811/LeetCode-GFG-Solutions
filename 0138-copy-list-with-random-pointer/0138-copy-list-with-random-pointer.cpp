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
        
        unordered_map<Node*,Node*> mp;
        
        Node* prevNode =NULL ;
        Node* head1 = head;
        Node* head2 = NULL;
        
        while(head1){
              Node* temp = new Node(head1->val);
               if(head2==NULL){
                   head2= temp;
                   prevNode = temp;
               }
             else{
                  prevNode->next = temp;
                  prevNode = temp;
             }
            mp[head1] = temp;
            head1=head1->next;
        }
        head1 = head;
        prevNode = head2;
        while(head1){
            if(head1->random){
               prevNode->random = mp[head1->random];
            }
            prevNode= prevNode->next;
            head1 = head1->next;
        }
        
       return head2; 
    }
};