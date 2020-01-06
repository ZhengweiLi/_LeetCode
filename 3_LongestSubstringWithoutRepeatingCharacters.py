class Solution(object):
    def lengthOfLongestSubstring(self, s):
        len_s=len(s)
        if len_s==0:
            return 0
        set_s=set(s)
        max_len=len(set_s)
        if max_len==1:
            return 1
        while max_len:
            i=0
            while i+max_len<=len_s:
                sub_s=s[i:i+max_len]
                set_sub_s=set(sub_s)
                if len(set_sub_s)==len(sub_s):
                    return len(sub_s)
                i=i+1
            max_len=max_len-1
