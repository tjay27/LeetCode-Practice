class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b){
        return a.first<b.first;
    }
    vector<int> twoSum(vector<int>& arr, int k) {
        vector<pair<int,int>> nums;
        for(int i=0;i<arr.size();i++){
            nums.push_back({arr[i],i});
        }
        sort(nums.begin(),nums.end(),cmp);
        vector<int> ans;
        int i=0;//start ptr
        int j=nums.size()-1;//end ptr
        
        while(i<j){
            cout<<nums[i].first<<' '<<nums[j].first<<endl;
            cout<<i<<' '<<j<<endl;
            int sum=nums[i].first+nums[j].first;
            if(sum==k){
                ans.push_back(nums[i].second);
                ans.push_back(nums[j].second);
                return ans;
            }
            else if(sum<k)
                i++;
            else 
                j--;
            
        }
        
        return ans;
    }
};