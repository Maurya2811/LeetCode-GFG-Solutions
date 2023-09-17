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
    void merge(int arr[], int l, int m, int r)
    {
         int left = m-l+1;
         int right = r-m;
         int arr1[left];
         int arr2[right];
         
        for(int i=0;i<left;i++){
            arr1[i]=arr[l+i];
        }
         for(int i=0;i<right;i++){
            arr2[i]=arr[m+1+i];
        }
        int k=l;
        int i=0;
        int j=0;
        while(i<left && j<right){
            if(arr1[i]<arr2[j]){
                arr[k++]=arr1[i++];
            }else{
                arr[k++]=arr2[j++];
            }
        }
        
        while(i<left){
             arr[k++]=arr1[i++];
        }
        while(j<right){
             arr[k++]=arr2[j++];
        }
        
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r)
        return ;
        
        int mid = (l+r)/2;
        
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends