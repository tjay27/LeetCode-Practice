class Solution {
public:
    bool validUtf8(vector<int>& data) {
        //convert each to binary
        //check the condition
        //if yes then check for the next n-1 bytes' condition
        vector<string> dataBin;
        for(auto &i: data){
            string ans="00000000";
            int k=0;
            while(i>0){
                ans[k++]=char(48+i%2);
                i/=2;
            }
            reverse(ans.begin(),ans.end());
            dataBin.push_back(ans);
        }
        int n=dataBin.size();
        int i=0;
        while(i<n){
            //n byte char
            if(dataBin[i][0]=='1'){
                //check the slices
                
                //4
                string str4=dataBin[i].substr(0,5);
                string str3=dataBin[i].substr(0,4);
                string str2=dataBin[i].substr(0,3);
                //cout<<str4<<' '<<str3<<' '<<str2<<endl;
                if(str4=="11110"){
                    if(i+3<n){
                        for(int j=i+1;j<=i+3;j++){
                            if(dataBin[j].substr(0,2)!="10")
                                return false;
                        }    
                        
                    }
                    else{
                        return false;
                    }
                    i+=4;
                }
                
                //3
                
                else if(str3=="1110"){
                    if(i+2<n){
                        for(int j=i+1;j<=i+2;j++){
                            if(dataBin[j].substr(0,2)!="10")
                                return false;
                        }
                        
                    }
                    else{
                        return false;
                    }
                    i+=3;
                }
                
                //2
                
                else if(str2=="110"){
                    if(i+1<n){
                        for(int j=i+1;j<=i+1;j++){
                            if(dataBin[j].substr(0,2)!="10")
                                return false;
                        }
                    }
                    else
                        return false;
                    i+=2;
                }
                
                else
                    return false;
                
            }
            //1 byte char
            else if(dataBin[i][0]=='0'){
                i++;
            }
        }
        return true;
    }
};
