class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<=1)     return s.size();
        int i=0, j=0;
        unordered_map <char,int> mpp;
        int ans = 0;
        while(j<s.size()){
            mpp[s[j]]++;
            while(mpp[s[j]]>1){
                mpp[s[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};