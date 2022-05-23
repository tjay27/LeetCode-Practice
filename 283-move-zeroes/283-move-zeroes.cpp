class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int str=0;
        int c=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]==0)
                c++;
            else{
                arr[str]=arr[i];
                str++;
            }
        }
        
        while(c--)
            arr[--n]=0;
        return;
    }
};