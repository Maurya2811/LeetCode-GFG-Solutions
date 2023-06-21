class Solution {
public:
    int n;
    long long calCost(vector<int>& nums, vector<int>& cost , int mid){
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+= (long long)abs(nums[i]-mid)*cost[i];
        }
        return sum;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        n = nums.size();
        int s = *min_element(nums.begin(), nums.end());
        int e = *max_element(nums.begin(), nums.end());
       long long sum=INT_MAX;
        while(s<=e){
            int mid = s + (e-s)/2;
           long long tempCost1 =calCost(nums,cost,mid);
            long long tempCost2 = calCost(nums,cost,mid+1);
            sum = min(tempCost1,tempCost2);
           
          if(tempCost2<=tempCost1)  {
                s=mid+1;
            }
            else
                e=mid-1;
        }
        return sum;
    }
};