class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int i=0, j=0;
        int n = arr.size();
        
        int ans = 0;
        
        queue<pair<int, int>> q;
        unordered_map<int, int> um;
        
        while(j<n){
            um[arr[j]]++;
            if(um.size()>k){
                q.push({i, j-1});
                
                while(um.size()>k){
                    um[arr[i]]--;
                    if(um[arr[i]] == 0)
                        um.erase(arr[i]);
                    i++;    
                }
                
            }
            
            j++;
                
        }
        q.push({i, j-1});
        
        while(!q.empty()){
            auto z = q.front();
            q.pop();
            
            int si = z.first;
            int se = z.second;
            
            int nn = se-si+1;
            int t = (nn*(nn+1))/2;
            
            ans += t;
            
            //common parts
            if(!q.empty()){
                auto m = q.front();
                int mi = m.first;
                int me = m.second;
                
                if(se >= mi){
                    int jj = se-mi+1;
                    int tt = (jj*(jj+1))/2;
                    ans -= tt;
                }
                
            }
            
            
        }
        
        return ans;
    }
};