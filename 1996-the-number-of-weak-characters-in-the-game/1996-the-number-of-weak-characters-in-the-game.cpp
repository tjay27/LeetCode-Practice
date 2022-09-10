class Solution {
    static bool cmp(const vector<int> &a,const vector<int> &b){
        if(a[0]!=b[0])
            return a[0]<b[0];
        return a[1]>b[1];
    }
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n=properties.size();
        sort(properties.begin(),properties.end(),[](const vector<int> &a,const vector<int> &b){
            if(a[0]!=b[0])
            return a[0]<b[0];
            return a[1]>b[1];
        });
        int maxDef=INT_MIN;
        int weak=0;
        for(int i=n-1;i>=0;i--){
            if(properties[i][1]<maxDef)
                weak++;
            maxDef=max(maxDef,properties[i][1]);
        }  
        return weak;
    }
};