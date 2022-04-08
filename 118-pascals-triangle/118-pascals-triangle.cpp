class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
	vector<int> r1;
	r1.push_back(1);
	ans.push_back(r1);
	
	for(int i=1;i<n;i++){
		vector<int> r;
		r.push_back(1);
		for(int j=0;j<ans[i-1].size()-1;j++){
			r.push_back(ans[i-1][j]+ans[i-1][j+1]);
		}
		r.push_back(1);
		ans.push_back(r);
	}
	
	return ans;
    }
};