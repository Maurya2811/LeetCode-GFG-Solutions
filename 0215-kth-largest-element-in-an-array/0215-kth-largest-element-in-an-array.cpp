// Using Min Heap
/*class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};
*/

// Using Quick Select

class Solution {
public:
    int partition(vector<int>&nums , int L , int R){
        int pivot = nums[L];
        int i =L+1;
        int j =R;
        
        while(i<=j){
            if(nums[i]<pivot && nums[j]>pivot){
                swap(nums[i],nums[j]);
                i++;
                j--;
                
            }else if( nums[i]>=pivot){
                i++;
            }
            else
                j--;
        }
        swap(nums[L],nums[j]);
        
        return j;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int L = 0;
        int R = nums.size()-1;
        int pvt_idx =0 ;
        
        while(true){
           pvt_idx = partition(nums,L,R);
            
            if(pvt_idx == k-1){
                break;
            }
            else if(pvt_idx < k){
                L = pvt_idx+1;
            }
            else{
                R = pvt_idx-1;
            }
        }
        return nums[pvt_idx];
    }
};