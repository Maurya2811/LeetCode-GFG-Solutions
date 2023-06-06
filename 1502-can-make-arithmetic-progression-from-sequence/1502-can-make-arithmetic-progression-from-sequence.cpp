class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(begin(arr),end(arr));
        // int diff = abs(arr[1]-arr[0]);
        int diff = arr[1]-arr[0];
        
        for(int i=2;i<arr.size();i++){
//            if(diff!=abs(arr[i]-arr[i-1]))
            if(diff!=arr[i]-arr[i-1])
                return false;
        }
        return true;
    }
};