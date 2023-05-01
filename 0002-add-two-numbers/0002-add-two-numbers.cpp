
class Solution {
public:
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = curr -> next;
        while(curr != NULL) {
                next = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = next;
        }
        return prev;
}
    
    ListNode* sum(ListNode* &head1, ListNode* &head2) {

        if(head1 == NULL)
                return head2;
        if(head2 == NULL)
                return head1; 

        // step1 : reverse both linked list
        // head1 = reverseLL(head1);
        // head2 = reverseLL(head2);

        //step2: add both linked list
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        int carry = 0;

        while(head1 != NULL && head2 != NULL) {
                //calculate sum
                int sum = carry + head1 -> val + head2 -> val;
                //find digit to create Listnode for
                int digit = sum % 10;
                //calculate carry
                carry = sum / 10;

                //create a new ListNode for the digit
                ListNode* newListNode = new ListNode(digit);
                //attach the newListNode into the answer wali linked list
                if(ansHead == NULL) {
                        //first Listnode insert krre ho
                        ansHead = newListNode;
                        ansTail = newListNode;
                }
                else {
                        ansTail -> next = newListNode;
                        ansTail = newListNode;
                }
                head1 = head1 -> next;
                head2 = head2 -> next;
        }

        //jab head1 list ki length head2 list se jada hogi
        while(head1 != NULL) {
                int sum = carry + head1 -> val;
                int digit = sum % 10;
                carry = sum / 10;
                ListNode* newListNode = new ListNode(digit);
                ansTail -> next = newListNode;
                ansTail = newListNode;
                head1 = head1 -> next;
        }

        //jab head2 list ki length head1 list se jada hogi
        while(head2 != NULL) {
                int sum = carry + head2 -> val;
                int digit = sum % 10;
                carry = sum / 10;
                ListNode* newListNode = new ListNode(digit);
                ansTail -> next = newListNode;
                ansTail = newListNode;
                head2 = head2 -> next;
        }

        //handle carry ko alag se
        while(carry != 0) {
                int sum = carry;
                int digit = sum % 10;
                carry = sum / 10;
                ListNode* newListNode = new ListNode(digit);
                ansTail -> next = newListNode;
                ansTail = newListNode;
        }


        //step3: reverse the ans linked list
        // ansHead = reverseLL(ansHead);
        return ansHead;
}
//     ListNode* sum( ListNode* &l1, ListNode* &l2){
//         ListNode* sumHead=NULL;
//          ListNode* sumTail=NULL;
//         int carry=0;
//         int sum=0;
//         int digit=0;
//         while(l1 && l2){
//             sum=l1->val+l2-> val+carry;
//             carry=sum%10;
//             digit=sum/10;   
//             ListNode* temp= new ListNode(digit);
//             if(sumHead==NULL){
//                 sumHead=temp;
//                 sumTail=temp;
//             }
//             else{
//                 sumTail->next=temp;
//                 sumTail=temp;
//             }
//             l1=l1->next;
//             l2=l2->next;
            
//         }
//          while(l1){
//             sum=l1->val+carry;
//             carry=sum/10;
//             digit=sum%10;   
//             ListNode* temp= new ListNode(digit);
//                 sumTail->next=temp;
//                 sumTail=temp;   
//             l1=l1->next;
//         }
//          while(l2){
//             sum=l2->val+carry;
//             carry=sum/10;
//             digit=sum%10;   
//             ListNode* temp= new ListNode(digit);
//               sumTail->next=temp;
//                 sumTail=temp;
//             l2=l2->next;
//         }
//         while(carry){
//              sum=carry;
//             carry=sum/10;
//             digit=sum%10;   
//             ListNode* temp= new ListNode(digit); 
//                 sumTail->next=temp;
//                 sumTail=temp;
//         }
//         sumHead=reverseLL(sumHead);
//         return sumHead;
//     }
    
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
//         ListNode*curr1=l1;
//         l1=reverseLL(curr1);
       
//         ListNode*curr2=l1;
//         l2=reverseLL(curr2);
        
       ListNode* ans= sum(l1,l2);
        
     return ans;
    }
};