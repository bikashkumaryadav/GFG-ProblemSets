class Solution {
  public:
   int minSoldiers(vector<int>& arr, int k) {
        // code here
        vector<int>v(k+1,0);
        int c = 0;
        int s = arr.size()%2 == 0 ? arr.size()/2 : (arr.size()/2)+1;
        for(auto it:arr){
            if(it % k == 0) c++;
            int index = k-(it%k);
            v[index]++;
        }
        if(c >= s) return 0;
        int i = 1 , ans = 0;
        while(i < k && c < s){
            if(v[i] > 0){
                int n = s-c;
                int f = v[i];
                if(n >= f){
                    ans += f*i;
                    c += f;
                }
                else{
                    ans += n*i;
                    break;
                }
            }
            i++;
        }
        return ans;
    }
};