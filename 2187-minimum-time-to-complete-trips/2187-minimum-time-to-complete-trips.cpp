class Solution {
public:
    #define lli long long int // lli is 64 bit range
    lli noOfTrips(vector<int>&time, lli t){
        //for a given time find the number of trips
        lli trips=0; 
        for(int i=0;i<time.size();i++){
            trips+=t/time[i];
        }
        return trips;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        /*long long t=0;
        while(totalTrips>0){
            t++;
            for(int i=0;i<time.size();i++){
                if(t%time[i]==0){
                    totalTrips--;
                }
            }
        } 
        return t;*/
        
       /* lli midT=(minT+maxT)/2;
        if(noOfTrips(time,midT)>totalTrips){
            maxT=midT;
            return minimumTime(time,totalTrips);    
        }
        else if(noOfTrips(time,midT)<totalTrips){
            minT=midT+1;
            return minimumTime(time,totalTrips);
        }    
        return midT;
        
    }*///wrong code
       //applying  binary search
        lli minT=1;
        lli maxT=1e14;
        
        while(minT<maxT){
            lli midT=(minT+maxT)/2;
            
            lli trips=noOfTrips(time,midT);
            
            if(trips>=totalTrips){
                //as we need to find minTime max time ko decrease
                maxT=midT;
            }
            else
                minT=midT+1;
        }
        return minT;
    } 
};
    