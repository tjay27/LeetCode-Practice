class Solution {
public:
    bool validP(string s, int c){
        if(c>1)
            return false;
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j])
                return (validP(s.substr(i+1,j-i),c+1)||validP(s.substr(i,j-i),c+1));
            else{
                i++;
                j--;
            }
        }
        return true;
            
    }
    
    bool validPalindrome(string s) {
        return validP(s,0);     
    }
};