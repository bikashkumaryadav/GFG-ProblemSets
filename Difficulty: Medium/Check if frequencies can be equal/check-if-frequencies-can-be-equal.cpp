class Solution {
    bool isEqual(vector<int>&f1){
        int f = -1;
        for(auto i : f1){
           if(i){
               if(f==-1) f= i;
               if(f != i) return 0;
           } 
        }
        return 1;
    }
  public:
    bool sameFreq(string& s) {
        // code here
        vector<int>f1(26,0);
        for(auto i : s) f1[i-'a']++;
        if(isEqual(f1)) return 1;
        
        for(auto i : s){
            f1[i-'a']--;
            if(isEqual(f1)) return 1;
            f1[i-'a']++;
        }
        return 0;
    }
};