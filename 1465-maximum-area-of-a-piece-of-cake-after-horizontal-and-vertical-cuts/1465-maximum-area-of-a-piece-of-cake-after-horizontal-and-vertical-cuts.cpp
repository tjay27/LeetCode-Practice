class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        verticalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        
        int numHorCuts=horizontalCuts.size();
        int numVerCuts=verticalCuts.size();
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        //finding the max consequent diff
        long hMax=INT_MIN;
        long vMax=INT_MIN;
        
        for(int i=0;i<numHorCuts-1;i++){
            long diff=horizontalCuts[i+1]-horizontalCuts[i];
            hMax=max(diff,hMax);
        }
         for(int i=0;i<numVerCuts-1;i++){
             long diff=verticalCuts[i+1]-verticalCuts[i];
             vMax=max(diff,vMax);
        }
        long sum=vMax*hMax;
        return sum%(1000000007);
        
        
    }
};