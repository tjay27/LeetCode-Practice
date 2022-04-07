class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        
        int max=0;
        while(i<j){
            int curr=min(height[i],height[j])*(j-i);
            if(curr>max){
                max=curr;
            }
            if(height[i]<height[j])
                i++;
            else
                j--;
            
        }
        return max;
    }
};