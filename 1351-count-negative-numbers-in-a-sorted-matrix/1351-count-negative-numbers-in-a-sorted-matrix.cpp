class Solution {
public:
    int search(int s, int e,vector<int> &ar){
        int ans_idx=-1;
        while(s<=e){
            int mid= s + (e-s)/2;
            if(ar[mid]<0){
                ans_idx =mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans_idx;
    }
    int countNegatives(vector<vector<int>>& arr) {
        int count =0;
        int m=arr.size();
        int n=arr[0].size();
        
        for(int i=0;i<m;i++){
            int temp = search(0,n-1,arr[i]);
            if(temp!=-1){
                count+=n-temp;
            }
        }
        return count;
    }
};