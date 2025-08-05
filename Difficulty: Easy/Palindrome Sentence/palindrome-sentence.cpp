class Solution {
  public:
  
    bool isPalindrome(string &str)
    {
        int start = 0 , end = str.size() - 1;
        while(start <= end)
        {
            if(str[start] != str[end])
                return false;
            start++ , end--;
        }
        return true;
    }
  
    bool isPalinSent(string &s) 
    {
        string str;
        for(char ch : s)
        {
            if(isalpha(ch) || isdigit(ch))
            {
                if(ch >= 'A' && ch <= 'Z')
                    ch = ch - 'A' + 'a';
                str.push_back(ch);
            }
        }
        if(isPalindrome(str))
            return true;
        else
            return false;
    }
};