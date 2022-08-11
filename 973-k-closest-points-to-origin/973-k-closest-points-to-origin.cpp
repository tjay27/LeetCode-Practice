class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //O(n) mein calculated the distance for each point
        //sort it on the basis of sum of mod of both of them, 
        sort(points.begin(),points.end(),[](vector<int> &a, vector<int> &b){
            return pow(a[0],2)+pow(a[1],2)<pow(b[0],2)+pow(b[1],2);
        });
        return vector<vector<int>> (points.begin(),points.begin()+k);
           
    }
};