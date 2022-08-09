class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int hours) {
        //the eating speed can go from 1 - max number of bananas in a pile.
        int minSpeed=1;
        int maxSpeed=*max_element(piles.begin(),piles.end());
        
        while(minSpeed<maxSpeed){
            int possibleSpeed=(long)(minSpeed+(long)maxSpeed)/2;
            //calculate the eating after each
            long hoursPresent=0;
            for(int i=0;i<piles.size();i++)
                hoursPresent+=ceil(1.0*piles[i]/possibleSpeed);
            if(hoursPresent<=hours){
                maxSpeed=possibleSpeed;
            }
            if(hoursPresent>hours){
                minSpeed=possibleSpeed+1;
            }
        }
        return minSpeed;
    }
};
