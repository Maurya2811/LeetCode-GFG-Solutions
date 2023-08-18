class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int maxi = -1;
        
        for(int i=n-1;i>=0 ;i--){
            int currEle = arr[i];
            arr[i] = maxi;
            maxi = max(maxi,currEle);
        }
        return arr;
    }
};