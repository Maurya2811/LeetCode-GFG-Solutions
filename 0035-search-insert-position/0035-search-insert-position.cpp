class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
    
        int s=0,e=arr.size()-1;
        int temp=-1;
      
        while(s<=e){
           int  mid= s + (e-s)/2;
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid]<target){
                temp=mid;
                s=mid+1;
            }
            else
                e=mid-1;
        }
        return temp+1;
    }
};