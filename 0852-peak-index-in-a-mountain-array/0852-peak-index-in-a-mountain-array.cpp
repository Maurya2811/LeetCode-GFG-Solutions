class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int s=0,e = n -1;
        int mid;
        while(s<e){
             mid = s + (e-s)/2 ;       
           if(arr[mid]<arr[mid+1]){
                s=mid+1;
            }
            else {
                e=mid;
            }
        }
        return e;
    }
};