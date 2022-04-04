class Solution {
public:
    /*int fib2(int n,vector<int> arr){
        if(n==0)
            arr[0]=0;
        if(n==1)
            arr[1]=1;
        if(n>1){
            if(arr[n]==-1){
                arr[n]=fib(n-1)+fib(n-2);
            }
        }
        
        return arr[n];
    }
    
    int fib(int n) {
        
        vector<int> arr(n+1,-1);
        return fib2(n,arr);
        
        
    }*/
    
    //dp
    
    int fib(int n){
        int *arr=new int[n+1];
        
        if(n<=1)
            return n; 
        arr[0]=0;
        arr[1]=1;
        for(int i=2;i<=n;i++){
            arr[i]=arr[i-1]+arr[i-2];
        }
        
        return arr[n];
    }
};


