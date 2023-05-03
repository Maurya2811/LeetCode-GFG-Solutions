//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
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


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends

// 2 Pointer Approach

int getNthFromLast(Node *head, int n)
{
       if(head==NULL)
       return -1;
      
       Node * temp=head;
       Node * curr=head;
       int i=1;
       while(i<n){
           temp=temp->next;
           if(temp==NULL)
           return -1;
           i++;
       }
       while(temp->next ){
           temp=temp->next;
           curr=curr->next;
       }
       return curr->data;
}

