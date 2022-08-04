class MyCalendar {
    #include<unordered_map>
public:
    unordered_map<int,int> mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        //check if overlaps
        for(auto &i: mp){
            //check with every interval
            int startL=i.first;
            int endL=i.second;
            if(start<endL && startL<end)
                return false;
        }
        mp.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */