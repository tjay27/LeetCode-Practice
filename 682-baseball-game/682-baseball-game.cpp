class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> arr;
        
        for(auto i:ops){
            if(i=="C"){
                arr.pop_back();
            }
            else if(i=="D"){
                arr.push_back(arr[arr.size()-1]*2);
            }
            else if(i=="+"){
                arr.push_back(arr[arr.size()-1]+arr[arr.size()-2]);
            }    
            else{
                arr.push_back(stoi(i));
            }
        }
        
        int s=0;
        for(auto i:arr)
            s+=i;
        return s;
    }
};