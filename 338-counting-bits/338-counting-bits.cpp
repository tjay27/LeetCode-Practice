class Solution {
public:
    vector<int> countBits(int n) {
        //brute force
        /*int pos=0;
        int prev2pow=1;
        int preveven=0;
        vector<int> ans;
        
        for(int i=0;i<=n;i++){
            if(i==0)
                ans.push_back(0);
            if(prev2pow*2==i){
                ans.push_back(1);
                prev2pow=i;
            }
            else if(i%2==0){
                
            }
            else if(i%2!=0){
                ans.push_back(ans[preveven]+1);
            }*///WRONG
       /* vector<int> ans;
        for(int i=0;i<=n;i++){
            if(i==0)
                ans.push_back(0);
            else if(i==1)
                ans.push_back(1);
            else
                ans.push_back(i%2+1);
        }
        return ans;*///WRONG
        vector<int> ans;
        for(int i=0;i<=n;i++){
            if(i%2==0)
                if(i==0)
                    ans.push_back(0);
                else if(i==2)
                    ans.push_back(1);
                else
                    ans.push_back(ans.at(i/2));
            else
                ans.push_back(ans.at(i-1)+1);
                
        }
        return ans;
    }
        
        
    
};