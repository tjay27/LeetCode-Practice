class Solution {
public:
    #include<unordered_map>
    string greatestLetter(string s) {
        unordered_map<char,int> low;
        unordered_map<char,int> high;
        
        
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]>=97)
                low[s[i]]++;
            else
                high[s[i]]++;
        }
        
        char max=64;
        char maxl=94;
        
        for(auto i:low){
            char caps=toupper(i.first);
            
            if(i.first>maxl){
                if(high.find(caps)!=high.end()){
                    max=caps;
                    maxl=i.first;
                }
            }
            
            
        }
        
        string ans="";
       // cout<<max+0;
        if(max==64){
            //cout<<max;
            return ans;
        }
        ans+=max;
        return ans;
        
        
    }
};