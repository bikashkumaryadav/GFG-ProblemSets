//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        // code here
        int n = str.size();
if (n == 0) return 0;
    unordered_set<char>unique_char(str.begin() ,str.end());
    int required=unique_char.size();
    unordered_map<char,int>window_count;
    int formed=0;
    int left=0;
    int min_length=INT_MAX;
    for(int i=0;i<n;i++){
        char ch=str[i];
        window_count[ch]++;
        if(window_count[ch]==1)
        formed++;
    
    while(formed==required){
        min_length=min(min_length,i-left+1);
        window_count[str[left]]--;
        if(window_count[str[left]]==0)
        formed--;
        left++;
    }
    }
    return(min_length==INT_MAX)?0:min_length;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends