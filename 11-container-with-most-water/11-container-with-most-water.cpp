class Solution {
public:
    #include<climits>
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;       
        int j=n-1;
        
        
        int maxAr=INT_MIN;
        while(i<j){
            int l1=height[i];       
            int l2=height[j];
            int area=(min(l1,l2)*(j-i));
            if(area>maxAr)
                maxAr=area;
            if(l1<l2)
                i++;
            else
                j--;
        }
        return maxAr;
        
        
    }
};