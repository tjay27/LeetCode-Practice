class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        //3 5 6 7 10 12
        //total grps will be less than n
        //FINd that i jiske lie i(i+1)/2 is less than n
        int i=grades.size();
        int n=grades.size();
        while(i>0&&n<long(i)*long(i+1)/2){
            i--;
        }
        return i;
    }
};