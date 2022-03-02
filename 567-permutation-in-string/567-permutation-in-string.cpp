class Solution {
public:
    #include<unordered_map>
    bool checkInclusion(string s1, string s2) {
        //check in the window of length of s1 which would traverse through s2
        /*int winStart=0;
        int winEnd=s1.length()-1;
        
        int winOfs1=0;//if this is 0 then feasible then yes
        int winOfs2=0;
        
        for(int i=0;i<s1.length();i++){
            winOfs1^=s1[i];
        }
        
        cout<<winOfs1<<' ';
        while(winEnd<s2.length()){
            for(int i=winStart;i<=winEnd;i++){
                winOfs2^=s2[i];
                cout<<s2[i];
            }
            cout<<endl;
            cout<<winOfs2<<endl;
            int x=winOfs2^winOfs1;
            
            if(x==0)
                return true;
            
            winOfs2=0;
            winStart++;
            winEnd++;
        }
        return false;*/
        /*unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        
        for(int i=0;i<s1.length();i++){
            m1[s1[i]]++;
        }
        
        while()*/
        if(s1.length()>s2.length())
            return false;
        //create a map for s1
        unordered_map<char,int> s1map;
        unordered_map<char,int> s2map;
        for(int i=0;i<s1.size();i++){
            s1map[s1[i]]++;
            s2map[s2[i]]++;
        }
        //create a window map
        int i=0;
        int j=s1.size();
        
        if(s1map==s2map)
                return true;
        while(j<s2.size()){
                s2map[s2[j]]++;
                s2map[s2[i]]--;
                if(s2map[s2[i]]==0)
                    s2map.erase(s2[i]);
                j++;
                i++;
            
            if(s1map==s2map)
                return true;
        }
        return false;   
    }
};