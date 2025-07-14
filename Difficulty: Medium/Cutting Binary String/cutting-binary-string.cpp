class Solution {
    map<string,int> countP(map<string,int> &mp)
    {
        int i = 1;
        while (true)
        {
            int x = i;
            string ans = "";
            while (x > 0)
            {
                int temp = x % 2;
                ans += ('0' + temp);
                x = x / 2;
            }
            reverse(ans.begin(), ans.end());
            if (ans.size() <= 30)
            {
                mp[ans]++;
            }
            else break;
            i = i * 5;
        }
        return mp;
    }
    int rec(int i, int j, string &s, map<string,int> &mp,vector<vector<int>> &dp)
    {
        if (s[i] == '0') return -1;
        if(dp[i][j]!=-1e5) return dp[i][j];
        string temp = "";
        for (int k = i; k <= j; k++)
        {
            temp += s[k];
        }
        if (mp.find(temp) != mp.end()) return 1;
        int ans = 1e9;
        for (int k = i; k < j; k++)
        {
            int p1 = rec(i, k, s, mp,dp);
            if (p1 == -1) continue;
            int p2 = rec(k + 1, j, s, mp,dp);
            if (p2 == -1) continue;
            ans = min(ans, p1 + p2);
        }
        return dp[i][j]=(ans!=1e9?ans:-1);
    }
public:
    int cuts(string s) {
        int n = s.size();
        map<string,int> mp;
        countP(mp);
        vector<vector<int>> dp(n,vector<int> (n,-1e5));
        return rec(0, n - 1, s, mp,dp);
    }
};