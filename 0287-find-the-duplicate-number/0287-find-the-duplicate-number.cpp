class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int i=0;
       while(a[a[i]]!=a[i])
       swap(a[a[i]],a[i]);
       return a[i];
    }
};