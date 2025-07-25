class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int n=arr.size();
        int normal_maxi=INT_MIN;
        int curr=0;
        //without circular just normal one
        for(int i=0;i<n;i++){
            curr+=arr[i];
            normal_maxi=max(normal_maxi,curr);
            if(curr<0){
                curr=0;
            }
        }
        int mini=INT_MAX;
        curr=0;
        int tot=0;
        bool all_neg=true;
        //for ciruclar one
        //circular=tot_sum-min_subarray_sum
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
                all_neg=false;
            }
            tot+=arr[i];
            curr+=arr[i];
            mini=min(mini,curr);
            if(curr>0){
                curr=0;
            }
        }
        int circular=tot-mini;
        //if all are negative 
        if(all_neg){
            return normal_maxi;
        }
        return max(normal_maxi,circular);
    }
};