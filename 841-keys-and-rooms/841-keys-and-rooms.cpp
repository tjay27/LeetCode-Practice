class Solution {
    void search(int i, vector<vector<int>> rooms,vector<int> &unlocked){
        if(unlocked[i]==1)
            return ;
        unlocked[i]=1;
        
        stack<int> st;
        st.push(i);
        
        while(!st.empty()){
            int top=st.top();
            st.pop();
            for(int j=0;j<rooms[top].size();j++){
                if(unlocked[rooms[top][j]]!=1&&i!=rooms[top][j]){
                    st.push(rooms[top][j]);
                    unlocked[rooms[top][j]]=1;
                }
            }
        }
        return ;
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n=rooms.size();
        vector<int> unlocked(n,0);
        //rooms is adjList
        search(0,rooms,unlocked);
        
        for(int i=0;i<n;i++){
            if(unlocked[i]!=1)
                return false;
        }
        return true;
    }
};