class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        /*vector<int> ans;
        for(auto it:nums)
            mp[it]++;
        for(auto it:mp){
            if(it.second==2)
                ans.push_back(it.first);
        }
        return ans;*/
        //as numbers lie in the range [1,n], turned to indices of [0,n-1]
        vector<int> ans;
        
        for(int i=0;i<arr.size();i++){
            int index=abs(arr[i])-1;  
            int flag=0;
            if(arr[index]<0)
                flag=1;
            arr[index]*=-1;
            if(flag==1)
                ans.push_back(index+1);
            
            
        }
        return ans;
        
    }
};