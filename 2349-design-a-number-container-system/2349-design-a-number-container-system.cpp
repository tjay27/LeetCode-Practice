class NumberContainers {
public:
  /*  #include<unordered_map>
    unordered_map<int,vector<int>> numidx;    //num-idx
    unordered_map<int,int> idxnum;     //idx-num
    unordered_map<int,int> smallestIndex;  //num-idx
    NumberContainers() {
               
    }
    
    void change(int index, int number) {
        //put that number at that index
        //uss index pr something already existed
        if(idxnum.find(index)!=idxnum.end()){
            //CURRENT NUMBER KI DEALING
            
            int prevNumber=idxnum[index];
            //idxnum mein add krna hai
            idxnum[index]=number;
            //if woh uss number ka smallest index hai toh smallest mein update 
            if(smallestIndex.find(number)||index<smallestIndex[number])
                smallestIndex[number]=index;
             //uss number ki list mein bhi add krna hai
            numidx[number].push_back(index);
            
            //PREV NUMBER KI DEALING
            //because kisi ki jgh le rha hai, uss number ke map mein so woh index remove numidx se
            numidx[prevNumber].erase(::find(numidx[prevNumber].begin(),numidx[prevNumber].end(),index));
            int prevIndex=smallestIndex[prevNumber];
            
            //agar wahi index smallest index tha toh hata do
            if(smallestIndex[prevNumber]==index){
                smallestIndex.erase(prevNumber);
                //find the number bigger than index in numidx
                if(numidx[prevNumber].size()!=0){
                    smallestIndex[prevNumber]=*min_element(numidx[prevNumber].begin(),numidx[prevNumber].end());
                }
            }
            if(numidx[prevNumber].size()==0){
                numidx.erase(prevNumber);
            }
        }
        //doesnt exist
        else{
            //added in index pair
            idxnum[index]=number;
            //added the new index to 
            numidx[number].push_back(index);
            //add in smallest index
            //if for the number there is no previous occurence
            if(smallestIndex.find(number)==smallestIndex.end())
                smallestIndex[number]=index;
            //if the number has occured before.
            else{
                if(index<smallestIndex[number])
                    smallestIndex[number]=index;
            }
            
        }
        return;
    }
    
    int find(int number) {
        if(smallestIndex.find(number)!=smallestIndex.end()){
            return smallestIndex[number];
        }
        return -1;
    }
};*/

  #include<unordered_map>
  #include<map>
    unordered_map<int,int> mp; //index - number
    unordered_map<int,set<int>> mp2; //number - indices
  NumberContainers() {
    
  }
  
  void change(int index, int number) {
      //if number at that index exists
      if(mp.find(index)!=mp.end()){
          int prevNumber=mp[index];
          //remove the index from prevNumber's index.
          mp2[prevNumber].erase(mp2[prevNumber].find(index));
          if(mp2[prevNumber].empty())
              mp2.erase(prevNumber);
      } 
      //no number is at that index
      mp[index]=number;
      mp2[number].insert(index);
     
      
  }
  
  int find(int number) {
     if(mp2.find(number)!=mp2.end())
         return *mp2[number].begin();
      return -1;
  }
};
