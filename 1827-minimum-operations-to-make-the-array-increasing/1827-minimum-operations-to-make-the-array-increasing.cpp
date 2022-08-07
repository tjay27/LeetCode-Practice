class Solution {
public:
    int minOperations(vector<int>& arr) {
        int n=arr.size();
        int max_so_far=INT_MIN;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]>max_so_far)
                max_so_far=arr[i];
            else{
                max_so_far++;
                cnt+=max_so_far - arr[i];
            }
        }
        return cnt;
    }
};