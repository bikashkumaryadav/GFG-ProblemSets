class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
        stack<char>st;
        for(char &ch:s){
            while(!st.empty() && st.top()<ch && k>0){
                st.pop();
                k--;
            }
            st.push(ch);
        }
        while(k>0){
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
