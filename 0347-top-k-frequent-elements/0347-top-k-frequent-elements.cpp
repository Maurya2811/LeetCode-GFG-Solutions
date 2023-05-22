// Two Appraoches

// Using Min Heap
/*
class Solution {
public:
    
    typedef pair<int,int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        
        for(int &num:nums){
            map[num]++;
        }
        
        priority_queue<P, vector<P>,greater<P>>pq;
        
        for(auto &it:map){
            int value=it.first;
            int freq = it.second;
            
            pq.push({freq,value});
            
            if(pq.size()>k)
                pq.pop();
            
        }
     
    vector<int> result;
    while(!pq.empty()){
        result.push_back(pq.top().second);
        pq.pop();
    }
    
    return result;
    }
};
*/

// Using Bucket Sort

// /*
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>map;
        for(int &num:nums){
            map[num]++;
        }
        
        vector<vector<int>>bucket(n+1);
        // Index = freq 
        // value = elements
        // bucket[i]= element having i frequency
        for(auto &x:map){
            bucket[x.second].push_back(x.first);
        }
        
        vector<int> result;
        // Pick elements from right to left from bucket to find out max freq element
         for(int i=n;i>=0;i--){
             if(bucket[i].size()==0)
                 continue;
             while(bucket[i].size()>0 && k>0){
                 result.push_back(bucket[i].back());
                 bucket[i].pop_back();
                 k--;
             }
             
         }
        
        return result;
     
    }
};
// */