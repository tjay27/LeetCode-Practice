class Solution {
int merge(vector<int>& arr,int si1,int ei1, int si2,int ei2){
    int i=si1;
    int j=si2;
    int k=0;
    int invPairs=0;
    vector<int> newArr(ei2-si1+1,0);
    //finding greater than 2*nums[j]
    //if arr[j]>INT_MAX/2 then dont' do.
    if(arr[j]<=INT_MAX/2){
        while(i<=ei1&&j<=ei2){
           // -inf/2, -inf, -inf/2-1, -inf-1
            // [-inf,+inf]
            // [-inf,-inf/2]
            // [-2inf,-inf]
            //arr[j]==int_max
            // inf/2, inf/2+1
            //[inf/2,inf]
            //[inf,2inf]
            if(arr[j]<=INT_MIN/2){
                invPairs+=ei1-i+1;
                j++;
            }
            else if(arr[i]>2*(long)arr[j]){
                invPairs+=ei1-i+1;
                j++;
            }    
            else{
                i++;
            }
        }
        
    }
    //merging arrays
    i=si1;
    j=si2;
    while(i<=ei1&&j<=ei2){
            if(arr[j]<arr[i]){
                //we can do this step better
                //find upperbound
                newArr[k++]=arr[j++];
            }
            else{
                newArr[k++]=arr[i++];
            }
        }
    while(i<=ei1)
        newArr[k++]=arr[i++];
    while(j<=ei2)
        newArr[k++]=arr[j++];
    
//        //copy(arr.begin()+si1,arr.begin()+ei2,newArr.begin());
     for(int i=si1;i<=ei2;i++){
         arr[i]=newArr[i-si1];
        // cout<<newArr[i-si1]<<' ';
    
     }
    
    // cout<<":"<<invPairs<<endl;
    return invPairs;
}
    
    int countPairs(vector<int>& arr,int si, int ei){
        if(si>=ei)
            return 0;
        
        int mid=(ei+si)/2;
        int revPairs1=countPairs(arr,si,mid);
        int revPairs2=countPairs(arr,mid+1,ei);
        
        return revPairs1+revPairs2+merge(arr,si,mid,mid+1,ei);
    }
public:
    #include<unordered_map>
    int reversePairs(vector<int>& arr) {
        //order matters so can't sort
        /*O(n^2)-approach, len is 5*10^4, total operations is 25*10^8, so can't do in 1 sec.
        // int n=arr.size();
        // int c=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(arr[i]>2*arr[j])
        //             c++;
        //     }
        // }
        // return c;
        // //map the indexes.
        int n=arr.size();*/
        //some self approach
       /*unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i); 
        }
        sort(arr.begin(),arr.end());
        //remove duplicates 
        int i=0;
        int k=0;
        while(i<n){
            if(arr[i]!=arr[i+1]){
                arr[k]=arr[i];
                k++;
            }
            i++;
        }
        //binary search to find the element just bigger than arr[i]*2
        int si=0;
        int ei=k-1;
        if(si==ei)
            return 0;
        int c=0;
        for(int i=si;i<ei;i++){

            if(arr[i]<INT_MAX/2 && arr[ei]>2*arr[i]){
                //finding the pos of number just bigger than target
                int target=2*arr[i];
                
                int start=i;
                int end=ei;
                int ind=-1;
                
                //FINDING THE POS WITH BINARY SEARCH
                while(start<=end){
                    int mid=(start+end)/2;
                    if(arr[mid]>target){
                        ind=mid;
                        end=mid-1;
                    }
                    else{
                        start=mid+1;
                    }
                }
                //IF THE NUMBERS GREATER THAN NUMS[I]*2 EXIST
                if(ind!=-1){
                    for(int num=ind;ind<=ei;ind++){
                        for(int ik=0;ik<mp[arr[]])
                        for(int k=0;k<mp[arr[num]].size();k++){
                            //cout<<mp[arr[num]][k]<<' ';
                            if(mp[arr[num]][k]<mp[arr[i]][])
                                c++;
                        }
                    }
                }
                
            }
            
            else
                break;
        }
        //cout<<endl;
        return c;
        */
        //count inversions style approach
        int n=arr.size();
        int a=countPairs(arr,0,n-1);
        //cout<<"the final array"<<endl;
        // for(int i=0;i<n;i++)
        //     cout<<arr[i]<<' ';
        // cout<<endl;
        return a;
}

};
