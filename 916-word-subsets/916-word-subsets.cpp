class Solution {
    #include<unordered_map>
    bool isSubset(string a, unordered_map<char,int> bmpmax){
        unordered_map<char,int> amp;
        for(int i=0;i<a.length();i++)
            amp[a[i]]++;

        for(auto i:bmpmax){
            if(amp.find(i.first)==amp.end())
                return false;
            
            if(amp[i.first]<bmpmax[i.first])
                return false;
        }
        return true;
    }
    unordered_map<char,int> findFreq(string s){
        unordered_map<char,int> ans;
        for(int i=0;i<s.size();i++)
            ans[s[i]]++;
        return ans;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> universal;
        unordered_map<char,int> bmpmax;
        
        for(int i=0;i<words2.size();i++){
            unordered_map<char,int> curr=findFreq(words2[i]);
            for(int j=0;j<words2[i].size();j++){
                int exist=INT_MIN;
                if(bmpmax.find(words2[i][j])!=bmpmax.end())
                    exist=bmpmax[words2[i][j]];
                bmpmax[words2[i][j]]=max(curr[words2[i][j]],exist);
            }
        }
                
        for(int i=0;i<words1.size();i++){
            if(isSubset(words1[i],bmpmax))
                universal.push_back(words1[i]);
        }
        
        return universal;
    }
    
};