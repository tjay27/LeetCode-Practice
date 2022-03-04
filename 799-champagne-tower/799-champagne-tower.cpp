/*class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double filledGlasses=(query_row+1)*(query_row+2)/2;
        if(poured<filledGlasses){
            double q=sqrt((poured-3)/4) -1.5;
            int qt=q;
            if(q-qt!=0){
                if(query_glass==0||query_glass=query_row-1){
                    
                }
            }
        }
        return 1;
    }
};
*/


class Solution {
    double dp[101][101];
public:
    double champagneTower(int p, int qr, int qg) {
        memset(dp,0,sizeof dp);
        dp[0][0] = p;
        for (int i = 0; i < 100; i++) 
            for (int j = 0; j <= i; j++) {
                if (dp[i][j] >= 1) {
                    double x=(dp[i][j] - 1) / 2.0;
                    dp[i][j] = 1;
                    
                    dp[i + 1][j] += x;
                    dp[i + 1][j + 1] +=x;
                    
                }
            }
        
        return dp[qr][qg];
    }
};