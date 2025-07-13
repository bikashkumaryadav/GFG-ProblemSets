class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>dp(n,1), dps(n,0);
        for(int i = 0; i < n; i++){
            dps[i] = arr[i];
        }
        
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(arr[j] > arr[i]){
                    if(dp[j] < dp[i] + 1){
                        dp[j] = dp[i] + 1;
                        dps[j] = dps[i] + arr[j];
                    }
                    else if(dp[j] == dp[i] + 1){
                        dps[j] = min(dps[j], dps[i] + arr[j]);
                    }
                }
            }
        }
        
        int mx = 0, total = 0, mxval = INT_MAX;
        for(int i = 0; i < n; i++){
            mx = max(mx, dp[i]);
            total += arr[i];
        }
        
        for(int i = 0; i < n; i++){
            if(mx == dp[i]){
                mxval = min(mxval, dps[i]);
            }
        }
        
        return total - mxval;
    }
};