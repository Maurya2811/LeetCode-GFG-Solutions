class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        set<int> st(nums.begin(),nums.end());

        vector<int>temp(st.begin(),st.end());

        int minCount = INT_MAX;

        for(int i=0 ; i<temp.size() ;i++){
           
           int L = temp[i];
           int R = L + n-1;
           int j = upper_bound(temp.begin(),temp.end(),R)-temp.begin();

           int numInsideRange = j-i;

           int numOutsideTheRange = n-numInsideRange;

           minCount = min(minCount,numOutsideTheRange);


        }

    return minCount;
    }
};