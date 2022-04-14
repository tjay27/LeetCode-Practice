class Solution {
public:
    static bool cmp(vector<int> a1, vector<int> a2){
        return a1[0]<a2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {    
        sort(intervals.begin(),intervals.end(),cmp);
        //int i=0;
        //merge with inspace->increases time complexity cuz erase takes o(n)
        /*while(i<intervals.size()){
            int j=i+1;
            while(j<intervals.size()&&intervals[i][1]>=intervals[j][0]){
                //merger
                intervals[i][1]=max(intervals[j][1],intervals[i][1]);
                //intervals.erase(intervals.begin()+j);
            }
            i++;
        }*/
        
        //merge with o(n) space
        vector<vector<int>> merged;
       /* for(int i=0;i<intervals.size();i++){
            for(int j=0;j<2;j++)
                cout<<intervals[i][j];
            cout<<' ';
        }
        cout<<"     ";*/
        merged.push_back(intervals[0]);
        int k=0;//traverses through merged
        int i=1; //traverses through intervals
        while(i<intervals.size()){
            //overlapping
            if(merged[k][1]>=intervals[i][0]){
                merged[k][1]=max(intervals[i][1],merged[k][1]);
               // cout<<"MAX:"<<intervals[i][1]<<intervals[k][1]<<endl;
            }
            //non overlapping
            else{
                merged.push_back(intervals[i]);
                k++;
            }
            i++;
           /* for(int i=0;i<merged.size();i++){
                for(int j=0;j<2;j++)
                    cout<<merged[i][j];
                cout<<' ';
                }
            cout<<endl;*/
         }
            
        return merged;
    }
};