class Solution {
    #include<unordered_map>
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> xorVals;
        
        int n=strs.size();
        for(int i=0;i<n;i++){
            string s=strs[i];
            sort(s.begin(),s.end(),[](char &a, char &b){
                return a<b;
            });
            xorVals[s].emplace_back(strs[i]);
        }  
        
        vector<vector<string>> ans;
        for(auto &i:xorVals){
            ans.emplace_back(i.second);
        }
        
        return ans;
    }
    
};