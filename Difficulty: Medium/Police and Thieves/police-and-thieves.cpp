class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int n=arr.size();
        int p=0,t=0;
        int l=0,r=0;
        int usedP=0,usedT=0;
        int ans=0;
        while(r<n){
            if((r-l)>k){
                if(arr[l]=='P'){
                    p--;
                    usedP=max(usedP-1,0);
                }
                else{
                    t--;
                    usedT=max(usedT-1,0);
                }
                l++;
            }
            if(arr[r]=='T'){
                if(p-usedP>0){
                    ans++;
                    usedP++;
                    usedT++;
                }
                t++;
            }
            else{
                if(t-usedT>0){
                    ans++;
                    usedT++;
                    usedP++;
                }
                p++;
            }
            r++;
        }
        return ans;
    }
};