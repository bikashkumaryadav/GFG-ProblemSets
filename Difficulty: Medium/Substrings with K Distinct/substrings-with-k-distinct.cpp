class Solution {
  public:
  int f(string &s,int k){
      int l=0,r=0;
        int cnt=0;
        int n=s.size();
        vector<int>mp(26,0);
        int distinct=0;
        while(r<n){
            mp[s[r]-'a']++;
            if(mp[s[r]-'a']==1) distinct++;
            while(l<n && distinct>k){
                mp[s[l]-'a']--;
                if(mp[s[l]-'a']==0){
                    distinct--;
                }
                l++;
            }
            r++;
            cnt+=(r-l+1);
        }
        return cnt;
  }
    int countSubstr(string& s, int k) {
        return f(s,k)-f(s,k-1);
    }
};