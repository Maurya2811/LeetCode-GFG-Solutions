class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& arr){
   stack<int> st;
    vector<int> ans;
    int n=arr.size();
    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            ans.push_back(-1);
        }
        else if(st.top()>arr[i]){
            ans.push_back(st.top());
        }
        else if(st.top()<=arr[i]){
            while(st.size()!=0 && st.top()<=arr[i]  ){
                st.pop();
            }
            if(st.size()==0){
            ans.push_back(-1);     
            }else{
                 ans.push_back(st.top());
            }
        }
        st.push(arr[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;   
    }
      
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
          vector<int> temp= nextGreaterElement(nums2);
        vector<int> ans;
        for(int i=0;i<nums2.size();i++){
           map[nums2[i]]=i;
        }
        
        for(int i=0;i<nums1.size();i++){
            ans.push_back(temp[map[nums1[i]]]);
        }
        return ans;
    }
};