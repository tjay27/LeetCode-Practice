class Solution {
    /*long long fact(int n){
        long long mod = 1000000007;
        return (n == 1 || n == 0) ? 1 : (fact(n - 1) * n)%mod;
    }*/
public:
    #include<cmath>
    int countOrders(int n) {
        /*long long mod = 1000000007;
        //n=3
        //_ _ _ _ _ _
        //p1,p2,p3,d1,d2,d3
        return int(fact(2*n)/pow(2,n))%mod;//%(pow(10,9)+7);*/
        /*long long mod=1000000007;
        long long ans=1;
        for(int i=2;i<=2*n;i++){
            ans*=i;
            ans%=mod;
        }
        return ans/pow(2,n);*/
        long long ans = 1;
        for (int i=2;i<=2*n;i++){
            ans*=i;  // calculating factorial
            
         if (i%2==0){
                 ans/=2;  // simultaneously dividing my ans by 2 everytime i is even (hence total N number of times)
             }
            ans = ans%((long long)pow(10,9)+7);  // modulo to get rid of overflow error
        }
        return ans;     
    }
};