class Solution {
public:
    #include<unordered_set>
    bool hasAllCodes(string s, int k) {  
       unordered_set<string> set;
       int n=pow(2,k);
        //if number of unique elements in set s n, then yes.
        int len=s.length();
        int i=0;
        while(i<=len-k){
            string str=s.substr(i,k);
            if(set.find(str)==set.end()){
                set.insert(str);
                n--;
            }
            if(!n)
                return true;
            i++;
        }
        return false;
    }
    
};