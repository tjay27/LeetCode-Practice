class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        //storing the last day for a task
        unordered_map<long long, long long> lastOfTaskType;
        long long currday=1;
        for(auto &a:tasks){
            if(lastOfTaskType[a]){
                lastOfTaskType[a]=std::max(lastOfTaskType[a]+space+1,currday);
                currday=lastOfTaskType[a]+1;
            }
            else{
                lastOfTaskType[a]=currday++;
            }
        }
        return currday-1;
    }
};