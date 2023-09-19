class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int slow =0,fast=0;
        slow=a[slow];
        fast=a[a[fast]];
        while(slow!=fast){
            slow=a[slow];
            fast=a[a[fast]];
        }
        fast=0;
        while(slow!=fast){
            slow=a[slow];
            fast=a[fast];
        }
        return slow;
    }
};