class Solution {
public:
    #include<queue>
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int i=0;
        while(i<stones.size()){
            
            pq.push(stones[i]);
            i++;
        }
        while(pq.size()>1){
            int l=pq.top();
            pq.pop();
            int sl=pq.top();
            pq.pop();
            if(l!=sl){
               // pq.pop();
                pq.push(l-sl);
            }
        }
        
        
        return pq.size()==0?0:pq.top();
    }
};