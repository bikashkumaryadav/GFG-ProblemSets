class Solution {
  public:
    bool check(int mid,vector<int>&arr,int k){
        int hours=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            // if its multiple of mid then we can directly divide 
            // else it will be floor+1
            if(arr[i]%mid==0){
                hours+=(arr[i]/mid);
            }
            else{
                hours+=(arr[i]/mid)+1;
            }
            if(hours>k) return false;
        }
        return true;
    }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        // do structured thinking in every q
        
        // i have to find minimum s
        // now suppose i have lower s than it will take more hours
        // and if less s than i will take less hours
        // thus i can partition using binary search on ans
        
        int n=arr.size();
        int l=1;
        int r=*max_element(arr.begin(),arr.end());
        
        int ans;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid,arr,k)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};