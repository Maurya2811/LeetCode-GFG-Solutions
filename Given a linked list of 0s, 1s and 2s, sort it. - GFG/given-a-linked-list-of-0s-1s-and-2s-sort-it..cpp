//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends

  // 2 Approaches
   //1 Brute Force  :: Replacing Values
 /*
class Solution
{
    public:
    int zero=0;
    int one=0;    
    int two=0;
    void counting(Node* &head){
         Node* temp=head;
       while(temp){
           if(temp->data==0)
               zero++;
        else if(temp->data==1)
               one++;
             else 
               two++;
          temp=temp->next;     
       }
    }
    Node* sorting(Node* &head){
        Node* temp=head;
        while(zero--)
        {
            temp->data=0;
            temp=temp->next;
        }
        while(one--)
        {
            temp->data=1;
            temp=temp->next;
        }
        while(two--)
        {
            temp->data=2;
            temp=temp->next;
        }
        return head;
    }
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
       if(head->next==NULL)
       return head;// Add code here
       
      counting(head);
      
     return sorting(head);
        
    }
};
*/
   
   // 2. Without Replacing Values
class Solution
{
    public:
    Node* sorting(Node* &head ){
    //     Node* zero = new Node(-1);
    //     Node* one = new Node(-1);
    //     Node* two = new Node(-1);
        
    //     Node* tailzero = zero;
    //     Node* tailone = one;
    //     Node* tailtwo = two;
        
    //     Node* curr=head;
    //     while(curr!=NULL){
         
    //         if(curr->data==0){
    //             Node *temp=curr;
    //             curr=curr->next;
    //             temp->next=NULL;
    //             tailzero->next=temp;
    //             tailzero= temp;
               
    //         }
    //         else if(curr->data==1){
    //              Node *temp=curr;
    //             head=head->next;
    //             temp->next=NULL;
    //             tailone->next=temp;
    //             tailone= temp;
               
    //         }
    //         else{
    //               Node *temp=curr;
    //              curr=curr->next;
    //              temp->next=NULL;
    //             tailtwo->next=temp;
    //             tailtwo= temp;
              
    //         }
    //     }
    //     Node* temp1=one;
    //           one=one->next;
    //           temp1->next=NULL;
    //           delete temp1;
                    
    //           temp1=two;
    //           two=two->next;
    //           temp1->next=NULL;
    //           delete temp1;
        
       
    //          if(one){
    //                 tailzero->next=one;
    //                 if(two){
    //                  tailone->next=two;
    //              }
    //          }
    //          else{
    //              if(two){
    //                  tailzero->next=two;
    //              }
    //          }
             
    //          temp1=zero;
    //         zero=zero->next;
    //         temp1->next=NULL;
    //         delete temp1;
       
    //     return head=zero;
         if(head == NULL) {
                cout << "LL is empty " << endl;
                return NULL;
        }
        if(head -> next == NULL) {
                //sngle node in LL
                return head;
        }

        //create dummy nodes
        Node* zeroHead = new Node(-101);
        Node* zeroTail = zeroHead; 

        Node* oneHead = new Node(-101);
        Node* oneTail = oneHead; 

        Node* twoHead = new Node(-101);
        Node* twoTail = twoHead; 

        //traverse the original LL
        Node* curr = head;
        while(curr != NULL) {

                if(curr -> data == 0) {
                        //take out the zero wali node
                        Node* temp = curr;
                        curr = curr -> next;
                        temp -> next = NULL;

                        //append the zero node in zeroHead LL
                        zeroTail -> next = temp;
                        zeroTail = temp;

                }
                else if(curr -> data == 1) {
                        //take out the one wali node
                        Node* temp = curr;
                        curr = curr -> next;
                        temp -> next = NULL;

                        //append the zero node in zeroHead LL
                        oneTail -> next = temp;
                        oneTail = temp;

                }
                else if(curr -> data == 2) {
                        //take out the zero wali node
                        Node* temp = curr;
                        curr = curr -> next;
                        temp -> next = NULL;

                        //append the zero node in zeroHead LL
                        twoTail -> next = temp;
                        twoTail = temp;

                }
        }

        //ab yha pr, zero , one, two, teeno LL readyv h 

        // join them 
        //remove dummmy nodes

        //modify one wali list
        Node* temp = oneHead;
        oneHead = oneHead -> next;
        temp -> next = NULL;
        delete temp;

        //modify two wali list
        temp = twoHead;
        twoHead = twoHead -> next;
        temp -> next = NULL;
        delete temp;

        //join list
        if(oneHead != NULL) {
                // one wali list is non empty
                //zero wali list ko one wali list se attach krdia 
                zeroTail -> next = oneHead;
                
                if(twoHead != NULL)
                        oneTail -> next = twoHead;
        }
        else{
                //one wali list is empty
                if(twoHead != NULL)
                        zeroTail -> next = twoHead;
        }

        //remove zerohead dummy Node
        temp = zeroHead;
        zeroHead = zeroHead -> next;
        temp -> next = NULL;
        delete temp;
        
        //return head of the modified linked list
        return zeroHead;

    }
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
       if(head->next==NULL)
       return head;// Add code here
       
     
      
     return sorting(head);
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends