class Solution {
  public:
    int lcsOf3(string& s1, string& s2, string& s3) {
        // Code here
        int dp[101][101][101];
        memset(dp,0,sizeof(dp));
        int n1=s1.size(),n2=s2.size(),n3=s3.size();
        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                for(int k=n3-1;k>=0;k--){
                    if(s1[i]==s2[j] && s2[j]==s3[k]){
                        dp[i][j][k]=1+dp[i+1][j+1][k+1];
                    }
                    else{
                        dp[i][j][k]=max({dp[i+1][j][k],dp[i+1][j][k+1],dp[i+1][j+1][k],dp[i+1][j+1][k+1], dp[i][j+1][k],dp[i][j+1][k+1],dp[i][j][k+1]});
                    }
                }
            }
        }
        return dp[0][0][0];
    }
};
