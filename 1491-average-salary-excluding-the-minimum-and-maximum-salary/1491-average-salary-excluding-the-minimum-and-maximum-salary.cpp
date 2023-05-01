class Solution {
public:
    double average(vector<int>& salary) {
  // 1. Brute Force 
        /*
        sort(salary.begin(),salary.end());
        int n=salary.size();
        long long sum=0;
        for(int i=1;i<n-1;i++){
            sum+=salary[i];
        }
        return (double)(sum)/(n-2);
        */
        int n=salary.size();
        int max= *max_element(salary.begin(),salary.end());
        int min= *min_element(salary.begin(),salary.end());
        int sum=accumulate(salary.begin(),salary.end(),0);
        sum=sum - (max+min);
        return (double)(sum)/(n-2);
    }
};