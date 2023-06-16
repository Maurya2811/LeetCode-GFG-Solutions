class Solution {
public:
    typedef long long ll;
    // #define ll long long
    ll MOD = 1e9 + 7;
    vector<vector<ll>>PT;
    
      int solve(vector<int>& nums){
          int n = nums.size();
          if(n<3)
              return 1;
          
          vector<int> leftArray , rightArray ;
          
          int root = nums[0];
          
          for(int i=1;i<n;i++){
              
              if(nums[i]<root)
                  leftArray.push_back(nums[i]);
              else
                  rightArray.push_back(nums[i]);
              
          }
          ll x = solve(leftArray)% MOD;
          ll y = solve(rightArray)% MOD;
          ll z= PT[n-1][leftArray.size()];
          
          return (((x*y)%MOD*z))%MOD     ;      
      }
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
       PT.resize(n+1) ;
        for(int i =0; i<= n; i++){
            
                 PT[i]= vector<ll>(i+1,1) ; 
            
                for(int j=1;j<i;j++){
                        PT[i][j]= (PT[i-1][j-1]+PT[i-1][j])%MOD;
                }
        }
        return (solve(nums)-1)%MOD;
    }
};