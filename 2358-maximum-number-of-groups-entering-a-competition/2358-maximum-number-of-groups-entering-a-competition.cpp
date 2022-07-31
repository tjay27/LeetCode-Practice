class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int k = 1;
        int ans = 0;
        int i = 0;
        while(i < grades.size()) {
            if (k > grades.size() - i){
                return ans;
            }
            i = i + k;
            ans++;
            k++;
        }
        return ans;
    }
};