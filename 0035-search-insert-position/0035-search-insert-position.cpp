class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        // if(target<arr[0])
        //     return 0;
        int s=0,e=arr.size()-1;
        int temp=-1;
        int mid=-1;
        while(s<=e){
             mid= s + (e-s)/2;
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