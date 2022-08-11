class Solution {
    //int LCS(string text1, string text2,int **lcs,int i1,int i2){
        //TOP-DOWN APPROACH
        /*if(i1==text1.length()||i2==text2.length())
            return 0;
        if(lcs[i1][i2]!=-1)
            return lcs[i1][i2];
        
        if(text1[i1]==text2[i2]){
            lcs[i1][i2]= 1+LCS(text1,text2,lcs,i1+1,i2+1);
        }
        else{
            int len1=LCS(text1,text2,lcs,i1,i2+1);
            int len2=LCS(text1,text2,lcs,i1+1,i2);
            lcs[i1][i2]=max(len1,len2);
        }
        
        return lcs[i1][i2];*/
   // }
    /*base case
        if(text1==""||text2=="")
            return 0;
        
        string t1=text1.substr(1);
        string t2=text2.substr(1);
        //cout<<t1<<' '<<t2;
        
        if(text1[0]==text2[0]){
           return 1+longestCommonSubsequence(t1,t2);
        }
        
        int len1=longestCommonSubsequence(t1,text2);
        int len2=longestCommonSubsequence(text1,t2);
        return max(len1,len2);
        
        //TOP DOWN APPROACH
        //store the repeated vals in lcs
        int n1=size(text1);
        int n2=size(text2);
        int **lcs=new int*[n1];
        for(int i=0;i<n1;i++){
            lcs[i]=new int[n2];
            for(int j=0;j<n2;j++){
                lcs[i][j]=-1;
            }
        }*/
    /*
        return LCS(text1,text2,lcs,0,0);     
        //BOTTOM UP APPROACH
        int n1=text1.size();
        int n2=text2.size();
        
        if(n1==0||n2==0)
            return 0;
        
        vector<vector<int>> lcs;
        for(int i=0;i<n1;i++){
            vector<int> v(n2,0);
            lcs.push_back(v);
        }
        
        if(text1[0]==text2[0])
            lcs[0][0]=1;
        
        
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                
                if(i==0&&j==0)
                    continue;
                
                int diag=(i-1>=0&&j-1>=0)?lcs[i-1][j-1]:0;
                int top=(i-1>=0)?lcs[i-1][j]:0;
                int left=j-1>=0?lcs[i][j-1]:0;
               // cout<<top<<' '<<diag<<' '<<left<<endl;
                
                if(text1[i]==text2[j])
                    lcs[i][j]=1+diag;
                else{
                    lcs[i][j]=max(top,left);
                        
                }
                    

            }
        }
      //  cout<<"--------------";
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                cout<<lcs[i][j]<<' ';
            }
            cout<<endl;
        }
        return lcs[n1-1][n2-1];*/
    int lcs_rec(string s1, string s2, int m, int n){
        if(m==0||n==0)
            return 0;
        if(s1[m-1]==s2[n-1])
            return 1+lcs_rec(s1,s2,m-1,n-1);
        return max(lcs_rec(s1,s2,m-1,n),lcs_rec(s1,s2,m,n-1));
    }
    int lcs_dp(string s1, string s2, int m, int n){
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        vector<int> prev(n+1,0);
        vector<int> curr(n+1);
        curr[0]=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1])
                    curr[j]=1+prev[j-1];
                else
                    curr[j]=max(curr[j-1],prev[j]);
            }
            prev=curr;
        }
        return curr[n];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        return lcs_dp(text1,text2,text1.length(),text2.length());
        
    }
};