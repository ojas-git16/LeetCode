class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0, right=0;
        int ans = 0;
        unordered_map <char,int> mpp;
        while(right < s.size()){
            int maxfreq = 0;
            mpp[s[right]]++;
            for(auto [key, val] : mpp)
                maxfreq = max(maxfreq, mpp[key]);
            if((right-left+1)-maxfreq > k){
                mpp[s[left]]--;
                left++;
            }
            else
                ans = max(right-left+1, ans);
            right++;
        }
        return ans;
    }
};