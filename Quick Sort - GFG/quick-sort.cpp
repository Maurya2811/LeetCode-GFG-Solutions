//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low>=high)
        return ;
        
         int s=low;
         int e=high;
         int pivot = arr[(low+high)/2];
        
         while(s<=e){
             
             while(arr[s]<pivot){
                 s++;
             }
             while(arr[e]>pivot){
                 e--;
             }
             
             if(s<=e){
                 swap(arr[s],arr[e]);
                     s++;
                     e--;
             }
         }
         
         quickSort(arr,low,e);
         quickSort(arr,s,high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
         
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends