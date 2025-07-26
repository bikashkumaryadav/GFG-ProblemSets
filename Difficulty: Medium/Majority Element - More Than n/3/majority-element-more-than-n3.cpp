class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        vector<int>ans;
       unordered_map<int,int>mp;
       int n=arr.size();
       for(int i=0;i<n;i++)
       {
           mp[arr[i]]++;
       }
       
       for(auto it:mp)
       {
           if(it.second>n/3)
             ans.push_back(it.first);
       }
       
       sort(ans.begin(),ans.end());
       return ans;
        
    }
};