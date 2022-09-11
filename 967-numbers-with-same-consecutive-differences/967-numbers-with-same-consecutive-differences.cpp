class Solution {
    #include<set>
    void hlpr(int n, int k,set<int> &output,int ans, int i){
        if(n==1){
            output.insert(ans);
            return ;
        }
        if(i+k>=0 && i+k<=9){  
            hlpr(n-1,k,output,ans*10+i+k,i+k);
        }
        if(i-k>=0 && i-k<=9){
            hlpr(n-1,k,output,ans*10+i-k,i-k);
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        set<int> temp;
        for(int i=1;i<=9;i++){
            hlpr(n,k,temp,i,i);
        }      
        vector<int> output(temp.begin(),temp.end());
        return output;
    }
};