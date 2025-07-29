class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
        unordered_map<char, vector<int>> ump;
        vector<int> ans;
        for(int i=0; i<s.size(); i++){
            ump[s[i]].push_back(i);
        }
        for(auto elm: ump){
            if(elm.second.size()<=1) continue;
            int sum=0;
            auto vec=elm.second;
            int front=vec.front();
            int back=vec.back();
            for(int i=front+1; i<=back-1; i++){
                sum+=int(s[i]);
            }
            if(sum==0) continue;
            ans.push_back(sum);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};