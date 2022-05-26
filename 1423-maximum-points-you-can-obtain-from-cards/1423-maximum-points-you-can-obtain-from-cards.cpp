class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //brute force- TLE - time complexity=O(2^n)
        //base case 
        /*int n=cardPoints.size();
        if(k==0)
            return 0;
        if(n==1)
            return cardPoints[0];
        else if(n==0)
            return 0;
        
        //recursive calls
        auto first=cardPoints.begin();
        auto last=cardPoints.begin()+n;
        vector<int> subarr1(first+1,last);
        vector<int> subarr2(first,last-1);
        int sum1=cardPoints[0]+maxScore(subarr1,k-1);
        int sum2=cardPoints[n-1]+maxScore(subarr2,k-1);
        cout<<endl;
        return max(sum1,sum2);*/
        //wrong approach
        /*int si=0,ei=cardPoints.size()-1,ans=0;
        while(k>0){
            if(cardPoints[si]>cardPoints[ei]){
                ans+=cardPoints[si];
                cout<<cardPoints[si];
                si++;
            }
            else if(cardPoints[si]<cardPoints[ei]){
                ans+=cardPoints[ei];
                cout<<cardPoints[ei];
                ei--;
            }
            else{
                if(cardPoints[si+1]>=cardPoints[ei-1]){
                    ans+=cardPoints[si];
                    cout<<cardPoints[si];
                    si++;
                }
                else{
                    ans+=cardPoints[ei];
                    cout<<cardPoints[ei];
                    ei--;
                }
            }
            k--;
        }
        cout<<endl;
        return ans;*/
        //sliding window
        
        int n=cardPoints.size();
        //length of window = n-k
        int winStart=0;
        int winEnd=n-k-1;
        
        int maxScore=0;
        int score=0;
        for(int i=n-k;i<n;i++)
            score+=cardPoints[i];
        maxScore=score;
        
        while(winEnd<n-1){
            score-=cardPoints[++winEnd];
            score+=cardPoints[winStart++];
            
            if(score>maxScore){
                maxScore=score;
            }
            //winEnd++;
           // winStart++;
        }
        
        return maxScore;
    }
};