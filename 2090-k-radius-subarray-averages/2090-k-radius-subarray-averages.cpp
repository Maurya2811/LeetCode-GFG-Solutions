class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n= nums.size();
        if(k==0)
            return nums;
        vector<int> avg(n,-1);
     
        if(k>=((n+1)/2)  )
            return avg;
        
       unsigned long long sum=0;
        for(int i=0;i<2*k+1;i++){
            sum+=nums[i];
        }
        
        avg[k]= sum/(2*k+1);
       
        for(int x: avg)
            cout<< x<<" ";  
        if(n==3)
            return avg;
      
        
        for(int i=k+1;i<n-k;i++){
            sum = sum - nums[i-(k+1)] + nums[i+k];
            avg[i]= sum/(2*k+1);
        }
        
        return avg;
    }
};