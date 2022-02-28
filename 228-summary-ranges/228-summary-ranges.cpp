class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        /*vector<string> ans;
        int n=nums.size();
        int i=0;
        int rangelength=1;
        int firstele=0;
        int lastele=0;
        while(i<n){
            if(rangelength==1){
                firstele=nums[i];
            }
            
            if(i+1<n&&nums[i+1]==nums[i]+1){
                rangelength++;
                lastele=nums[i+1];
            }
            else if(i==n-1){
                lastele=nums[i];
            }
            
            else{
                string s="";
                if(rangelength==1){
                    s+=char(firstele+48);
                    ans.push_back(s);
                }
                else{
                    s+=char(firstele+48);
                    s+='-';
                    s+='>';
                    s+=char(lastele+48);
                    ans.push_back(s);
                }
                rangelength=1;
            }
            i++;
        }
        return ans;*/ //CODE NOT CLEAN
        int rangeLength=1;
        vector<string> ans;
        int firstele=0;
        int lastele=0;
        int i=0;
        int n=nums.size();
        while(i<n){
            if(rangeLength==1)
                firstele=nums[i];
            if(i!=n-1&&nums[i]+1==nums[i+1]){
                rangeLength++;
                lastele=nums[i+1];
            }
            else{
                string s="";
                if(rangeLength==1){
                    s+=to_string(firstele);
                    ans.push_back(s);
                }
                else{
                    s+=to_string(firstele);
                    s+="->";
                    s+=to_string(lastele);
                    ans.push_back(s);
                    rangeLength=1;
                }
            }
            i++;
        }
        return ans;
    }
};