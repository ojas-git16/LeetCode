class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0; i<haystack.size(); i++)
        {
            int x=i;
            if(haystack[i]==needle[0])
            for(int j=0; j<needle.size() && i<haystack.size(); j++,i++)
            {
                if(needle[j]!=haystack[i])
                    break;
                if(j==needle.size()-1 && needle[j]==haystack[i])
                    return x;
            }
            i=x;
        }
        return -1;
    }
};