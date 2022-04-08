class KthLargest {
    /*#include<queue>
    int k;
    vector<int> nums;
    int klidx;//idx of kth largest element
    //priority_queue<int> pq;
    //int kthLargest=0;*/
    
public:    
   // KthLargest(int k, vector<int>& nums) {
       
        /* 
       this->k=k;
        this->nums=nums;
        sort(nums.begin(),nums.end());
        kl=nums.size()-k;
    }
    
    
    int add(int val) {
        pq.push(val);
        int i=k;
        vector<int> extra;
        while(i>1){
            extra.push_back(pq.top());
            pq.pop();
            i--;
        }
        int ans=pq.top();
        i=0;
        while(i<k-1){
            pq.push(extra[i]);
            i++;
        }
        nums.push_back(val);
          
        if(val>nums[klidx])
            sort(nums.begin(),nums.end());
        
        return nums[nums.size()-k];
    }*/
    
    
//};
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int x : nums) {
            pq.push(x);
            if(pq.size() > k) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > K) {
            pq.pop();
        }
        return pq.top();
    }
};
    
    
    
    