class Solution:
    def longestKSubstr(self, s, k):
        d = dict()
        start = ans = 0
        
        for i in range(len(s)):
            d[s[i]] = d.get(s[i], 0) + 1
            
            while len(d) > k:
                d[s[start]] -= 1
                if d[s[start]] == 0:
                    del d[s[start]]
                
                start += 1
            
            if len(d) == k:
                ans = max(ans, i - start + 1)
        
        return ans if ans > 0 else -1