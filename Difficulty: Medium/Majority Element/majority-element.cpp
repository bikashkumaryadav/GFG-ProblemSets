//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
   int majorityElement(vector<int>& arr) {
        // code here
        unordered_map<int,int> mp;
        int n=arr.size();
        for(auto it:arr)
        {
            mp[it]+=1;
        }
        int ans=-1;  
       
        for(auto it:mp)
        {
            if(it.second>n/2)
            ans=it.first;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends