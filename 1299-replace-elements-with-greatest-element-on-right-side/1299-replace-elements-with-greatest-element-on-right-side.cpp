class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int cur; 
        int mx = arr[n - 1];
        arr[n - 1] = -1;
        for ( int i = n - 2; i >= 0; i--){
            cur = max(mx, arr[i]);
            arr[i] = mx;
            mx = cur;
        }
        return arr;
    }
};