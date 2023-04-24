class Solution {
public:
    // 2 Approaches
    // Brute Force
    int lastStoneWeight(vector<int>& stones) {
       
//         while(stones.size()>1){
            
//             sort(stones.begin(),stones.end());
//             int y=stones.back(); stones.pop_back();
//            int x= stones.back();
          
//            stones.pop_back();

//                 stones.push_back(y-x);
            
//         }
//    return stones[0];
//     }
    
// Priority Queue
    priority_queue<int> pq;
     for(int &x : stones ){
         pq.push(x);
     }
    while(pq.size()>1){
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        pq.push((a-b));
    }
    return pq.top();
}
};