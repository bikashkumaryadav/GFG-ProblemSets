class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n=arr.size();
        int ans=0;
        int curr=0;
        for(int i=1;i<n;i++){
            curr=arr[i]+arr[i-1];
            ans=max(ans,curr);
        }
        return ans;
    }
};