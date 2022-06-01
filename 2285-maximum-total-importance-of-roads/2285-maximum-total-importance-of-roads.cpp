class Solution {
public:
    static bool cmp(pair<int,int> a,pair<int,int> b){
            return a.first>b.first;    
    }
    #include<unordered_map>    
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        /*
        long long ans=0;
        vector<pair<pair<int,int>,int>> connections;
        int noOfroads=roads.size();
        
        for(int i=0;i<roads.size();i++){
            
                pair<pair<int,int>,int> p1;
                pair<pair<int,int>,int> p2;
                p1.first.first=roads[i][0];
                p2.first.first=roads[i][1];
                p1.first.second++;
                p2.first.second++;
                connections.push_back(p1);
                connections.push_back(p2);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==1){
                    pair<pair<int,int>,int> p;
                    p.first.first=i;
                    p.first.second++;
                    connections.push_back(p);
                }
            }
        }
        
        sort(connections.begin(),connections.end(),cmp);
        
        int connLength=connections.size();
        for(int i=0;i<connLength;i++){
            connections[i].second=n;
            
            n--;
        }
        
        // for(int i=0;i<noOfroads;i++){
        //     for(int j=0;j<a[i].size();j++){
        //         if(a[i][j]==1){
        //                ans+=connections[i].second+connections[j].second;
        //         }
        //     }
        // }
         
        return ans/2;*/
        pair<int,int>* noOfRoads=new pair<int,int>[n];
        
        for(int i=0;i<n;i++){
            noOfRoads[i].second=i;
        }
        for(int j=0;j<roads.size();j++){
            for(int i=0;i<2;i++){
                noOfRoads[roads[j][i]].first++;
            }
        }
        //for(int i=0;i<n;i++){
         //   cout<<noOfRoads[i].second<<' '<<noOfRoads[i].first<<endl;
        //}
        
        sort(noOfRoads,noOfRoads+n,cmp);
        for(int i=0;i<n;i++){
            //cout<<noOfRoads[i].second<<' '<<noOfRoads[i].first<<endl;
        }
        
        unordered_map<int,int> mp;
        int k=n;
        for(int i=0;i<n;i++){
            mp[noOfRoads[i].second]=k--;
          //  cout<<noOfRoads[i].second<<' '<<mp[noOfRoads[i].second]<<endl;
            
        }
        long long ans=0;
        for(int j=0;j<roads.size();j++){
            int x=0;
            for(int i=0;i<2;i++){
                //cout<<i<<endl;
                //x+=mp[roads[j][i]];
                ans+=mp[roads[j][i]];
                //cout<<ans;
                //cout<<n;
            }
           //cout<<x<<endl;;
            
        }
        return ans;
        
        
        
    }
};