class Solution {
   int findPivot(vector<int>& arr, int si, int ei){
       //4 5 6 0 1 2
       //4 5 6 6 0
       //4 5 0 1 1 2
       //4 0 1 2 3 3
       // 1 1 1 1 0
       int zero=si;
       int pivot=-1;
       while(si<=ei){
           int mid=(si+ei)/2;
           if(arr[mid]>=arr[0]){
               si=mid+1;
           }
           else if(arr[mid]<arr[0]){
               //this can be pivot
               pivot=mid;
               ei=mid-1;
           }
       }
       return pivot;
   } 
   bool binSearch(vector<int>& arr, int si, int ei,int target){
       //1 2 3 4 5 6 7
       while(si<=ei){
           int mid=(si+ei)/2;
           cout<<mid;
           if(target==arr[mid]){
               return true;
           }
           else if(target<arr[mid]){
               ei=mid-1;
           }
           else if(target>arr[mid]){
               si=mid+1;
           }
          // cout<<"si: "<<si<<' '<<"ei: "<<' '<<ei<<endl;
       }
       return false;
   }
public:
    bool search(vector<int>& arr, int target) {
        //skip the duplicates
        int n=arr.size();
        int si=0;
        int ei=n-1;
        while(si+1<ei && arr[si]==arr[si+1])
            si++;
        //find the pivot point
        while(ei>si && arr[ei]==arr[0])
            ei--;
        int pivot=findPivot(arr,si,ei);
        //do bin search in first or second half
        //cout<<si<<' '<<ei<<endl;
        //cout<<pivot<<endl;
        cout<<si<<" "<<ei<<endl;
        if(pivot==-1)
            return binSearch(arr,si,ei,target);
        
        if(target>arr[ei]){
            //in the first half
            return binSearch(arr,si,pivot-1,target);
        }
        else{
            return binSearch(arr,pivot,ei,target);
        }
        
        return false;
    }
};
/*class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        if( nums[0] == target or nums.back() == target ) return true; 
        // this line is redundant it reduces only the worst case when all elements are same to O(1)
        
        const int n = nums.size();
        int l = 0 , h = n-1;
        while( l+1 < n and nums[l] == nums[l+1]) l++;

        // if all elements are same
        if( l == n-1){
            if( nums[0] == target ) return true;
            else return false;
        }
        
        // while last element is equal to 1st element
        while( h >= 0 and nums[h] == nums[0] ) h--;
        int start = l , end = h;
        
        // find the point of pivot ie from where the rotation starts
        int pivot = -1;
        while( l <= h ){
            int mid = l + (h-l)/2;
            if( nums[mid] >= nums[0] ) l = mid+1;
            else {
                pivot = mid;
                h = mid-1;
            }
        }
        
        cout<<pivot<<endl;
        if( pivot == -1 ) l = start , h = end; // if no pivot exits then search space is from start -e end
        else {
            if( target > nums[end] ) l = start , h = pivot-1; // search space second half
            else l = pivot , h = end; // search space first half
        }
        
        // normal binary search
        while ( l <= h ){
            int mid = l + (h-l)/2;
            if( nums[mid] > target ) h = mid-1;
            else if( nums[mid] < target ) l = mid+1;
            else return true;
        }
        
        return false;
        
    }
};*/