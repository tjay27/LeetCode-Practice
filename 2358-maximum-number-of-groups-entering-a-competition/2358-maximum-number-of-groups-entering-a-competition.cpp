class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int i=1; //no of kids in ith grp
        int sum=0; //sum of all grps
        int totalGrps=0;
        int n=grades.size();
        //sum<=n
        while(sum<n&&i<=n-sum){
            sum+=i;
            totalGrps++;
            i++;
        }
        return totalGrps;
    }
};