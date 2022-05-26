class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        //int k=0;
        //cout<<n<<endl;
        while(n>0){
           // k++;
            if(n%2==1)
                ans++;
            n/=2;
        }
        //cout<<k;
        return ans;
    }
};