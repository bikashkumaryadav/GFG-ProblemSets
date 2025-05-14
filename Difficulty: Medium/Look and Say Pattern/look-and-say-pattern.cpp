//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string countAndSay(int n) {
        string str="1";
        if(n==1)
        return str;
        while(n>1){
            string S="";
            int cnt=1;
            for(int i=1;i<str.length();i++){
                if(str[i]==str[i-1])
                cnt++;
                else{
                    S+=to_string(cnt);
                    S+=str[i-1];
                    cnt=1;
                }
            }
            S+=to_string(cnt);
            S+=str.back();
            str=S;
            n--;
        }
        return str;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends