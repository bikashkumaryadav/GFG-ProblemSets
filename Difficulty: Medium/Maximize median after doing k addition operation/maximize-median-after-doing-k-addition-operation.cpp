class Solution {
  public:
    bool Possible(vector<int>& arr, int k,int mid,int idx){
        int diff=0;
        for(int i=idx;i<arr.size();i++)if(mid>=arr[i])diff+=mid-arr[i];
        if(diff<=k)return true;
        return false;
    }
    int maximizeMedian(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int idx=(n-1)/2;
        
        int len=n-idx;
        int d=k/len;
        int low=arr[idx]+d,high=arr[n-1]+d;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(Possible(arr,k,mid,idx)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        if(n%2==1)return ans;
        int e1=max(ans,arr[idx+1]);
        return (e1+ans)/2;
    }
};