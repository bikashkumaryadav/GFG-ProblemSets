class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) 
    {
        int n=arr.size();
        unordered_map<int,int> mp;
        vector<int> vec(n,0), ans;
        stack<pair<int,int>> st;    // freq,ind
        
        // store fre
        for(int i=0; i<n; i++)    mp[arr[i]]++;
        
        // freq of element at each index
        for(int i=0; i<n; i++)    vec[i]=mp[arr[i]];
        
        // traverse in stack
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && st.top().first<=vec[i])  st.pop();
            
            if(st.empty())  ans.push_back(-1);
            else    ans.push_back(arr[st.top().second]);
            
            st.push({vec[i],i});
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};