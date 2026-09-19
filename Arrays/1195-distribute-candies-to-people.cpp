class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        vector<int> ans(n, 0);
        int give = 1, i = 0;
        while(candies > 0) {
            ans[i] += min(give, candies);
            candies -= give;
            give++;
            i++;
            if(i>=n)
                i=0;
        }
        return ans;
    }
};