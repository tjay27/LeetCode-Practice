class Solution {
int whoWins(vector<int>& piles, int i, int j, int aliceScore, int bobScore, int aliceTurn, vector<vector<int>> &dp){
        if(i==j)
            return aliceScore>bobScore ? 1:0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        // if alice's turn
        if(aliceTurn){
            bool pickStart=whoWins(piles, i+1, j, aliceScore+piles[i], bobScore, 0, dp);
            bool pickEnd=whoWins(piles, i, j-1, aliceScore + piles[j], bobScore , 0, dp);
            return dp[i][j]=pickStart || pickEnd;
        }
        else{
            bool pickStart=whoWins(piles, i+1, j, aliceScore, bobScore + piles[i], 1, dp);
            bool pickEnd=whoWins(piles, i, j-1, aliceScore, bobScore + piles[j], 1, dp);
            return dp[i][j]=pickStart || pickEnd;
        }
        
        return false;
    }
// int whoWins_dp(vector<int>& piles){
//     //if number of piles = 1, then alice will win 
//     vector<vector<int>> d
// }
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        int i=0;
        int j=n-1;
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return whoWins(piles, i, j, 0, 0, 1, dp)?true : false;
    }
};