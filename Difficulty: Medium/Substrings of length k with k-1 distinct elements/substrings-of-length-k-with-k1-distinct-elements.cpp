class Solution {
  public: int substrCount(string &s, int k) {
        // code here
        unordered_map<char, int>mp;
        int cnt=0;
        for(int i=0; i<k; i++){
            mp[s[i]]++;
        }
        if(mp.size()==k-1) cnt++;
        for(int j=k; j<s.size(); j++){
             char charToAdd = s[j];           
            char charToRemove = s[j - k];
            mp[charToAdd]++;
            mp[charToRemove]--;
            if(mp[charToRemove]==0) mp.erase(charToRemove);
            if(mp.size()==k-1) cnt++;
        }
        return cnt;
    }
};