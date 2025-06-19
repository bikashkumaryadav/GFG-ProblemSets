class Solution {
  public:
    string caseSort(string& s) {
        string lc="";
        string uc="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='a'&&s[i]<='z')lc+=s[i];
            else uc+=s[i];
        }
        sort(lc.begin(),lc.end());
        sort(uc.begin(),uc.end());
        int u=0,l=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='a'&&s[i]<='z')
            {
                s[i]=lc[l++];
            }
            else s[i]=uc[u++];
        }
        return s;
    }
};