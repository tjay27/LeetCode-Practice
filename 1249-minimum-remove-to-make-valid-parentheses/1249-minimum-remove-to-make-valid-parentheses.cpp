class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='('||s[i]==')'){
                if(stk.empty()){
                    stk.push(i);
                }
                else{
                    if(s[i]==')'){
                        if(s[stk.top()]=='(')
                            stk.pop();
                        else
                            stk.push(i);
                    }
                    else{
                        stk.push(i);}
                }
            }
            else
                continue;
        }
        //remove the elements in stk
        int i=s.length()-1;
        while(i>=0){
            if(!stk.empty()&&stk.top()==i){
                //i--;
                stk.pop();
            }
            else
                ans+=s[i];
            i--;
        }
        std::reverse(ans.begin(),ans.end());
        return ans;
    }
};