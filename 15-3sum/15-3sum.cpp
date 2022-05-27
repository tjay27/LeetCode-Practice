class Solution {
public:
    #include <unordered_map>
    #include <set>
    vector<vector<int>> threeSum(vector<int>& arr) {
        //APPROACH-1, BRUTE FORCE TIME=O(N^3logm), SPACE=O(logm)
        /* map<vector<int>,bool> mp; //we use map here bcz can't do vector<int> with umap as umap uses hashing and u can't hash a vector or a pair
        vector<vector<int>> ans;
        
        int n=arr.size();
        //sort(arr.begin(),arr.end());
        
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){
                
                for(int k=j+1;k<n;k++){
                    
                    if(arr[i]+arr[j]+arr[k]==0){
                        
                        vector<int> v={arr[i],arr[j],arr[k]}; 
                        sort(v.begin(),v.end());
                        
                        if(mp.find(v)==mp.end()){
                            mp[v]=true;
                            ans.push_back(v);
                            
                           // cout<<true;
                        }
                            
                            //cout<<true;
                        
                    }
                }
            }
        }
        
        return ans;*/
        
        //APPROACH-2, TIME->(no of occurences*n*n*logm), space=>O(n)+O(m)
        //add to hashmap value of c and 2 loops
        //use set to avoid repeated triplets(i,j,k)(j,k,i)..
        //set compares the vectors completely ie elements and orders all must be same
       /*  unordered_map<int,vector<int>> mp; //number, freq
        set<vector<int>> ans;
        vector<vector<int>> finalAns;
        int n=arr.size();
        for(int i=0;i<arr.size();i++)
            mp[arr[i]].push_back(i);
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                int target=-(arr[i]+arr[j]);
                if(mp.find(target)!=mp.end()){
                    //if(mp[target].find(i)!=mp[target].end()||mp[target].find(j)!=mp[target].end())
                    for(int k=0;k<mp[target].size();k++){
                        vector<int> v={arr[i],arr[j]};
                        if(mp[target][k]!=i&&mp[target][k]!=j){
                            v.push_back(target);
                            sort(v.begin(),v.end());
                            //if(ans.find(v)==ans.end())
                            ans.insert(v);
                        }//, so bas thoda kam hua.
                    }
                }
                
            }
        }
        
        //copy(ans.begin(),ans.end(),finalAns.begin());
        for(auto &it: ans){
            finalAns.push_back(it);
        }
        return finalAns;    
    */
        
       //APPROACH-2(II)->storing the values in hashmap but freq only Time=>O(n^2logm),  `                    space=O(n)+O(m)      
        /*set<vector<int>> ans;
        vector<vector<int>> finalAns;
        unordered_map<int,int> mp;
        
        int n=arr.size();
        
        for(int i=0;i<n;i++)
            mp[arr[i]]++;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                int target=-(arr[i]+arr[j]);
                mp[arr[i]]--;
                mp[arr[j]]--;
                if(mp.find(target)!=mp.end()&&mp[target]>0){
                    vector<int> v={arr[i],arr[j],target};
                    sort(v.begin(),v.end());
                    ans.insert(v);
                }
                mp[arr[i]]++;
                mp[arr[j]]++;
                
            }
        }
        
        //copy(ans.begin(),ans.end(),finalAns.begin());
        
        for(auto &it: ans)
            finalAns.push_back(it);
        return finalAns;*/
        
       // APPROACH-3, 2 ptr approach <===> one ptr moves for sum, the rest 2 are in 2 ptr approach
        
        int k=0;
        int n=arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        
        //one ptr to traverse the whole array
        while(k<n-2){
            
            int target=-arr[k];
            int i=k+1;
            int j=n-1;
            
            //2 pointers to find the target sum
            while(i<j){
                    
                    if(arr[i]+arr[j]==target){
                        vector<int> v={arr[k],arr[i],arr[j]};
                        ans.push_back(v);
                       // cout<<k<<i<<j;
                        //int flag=0;
                        i++;
                        while(i<n&&arr[i]==arr[i-1])
                            i++;
                        // while(arr[i]==arr[i+1]){
                        //     flag=1;
                        //     i++;
                        // }
                        // if(!flag)
                        //     i++;
                        j--;
                        while(j>0&&arr[j]==arr[j+1])
                            j--;
                        
                        // flag=0;
                        // while(arr[j]==arr[j-1]){
                        //     flag=1;
                        //     j--;
                        // }
                        // if(!flag)
                        //     j--;
                    }   
                    
                    else if(arr[i]+arr[j]<target){
                        i++;
                        while(i<n&&arr[i]==arr[i-1])
                            i++;
                    }
                    
                    else if(arr[i]+arr[j]>target){
                        j--;
                        while(j>0&&arr[j]==arr[j+1])
                            j--;
                    }
                    
                }
            k++;
            //int flag=0;
            while(k<n-2&&arr[k]==arr[k-1])
                k++;
            
        }
        return ans;
        
    }
};