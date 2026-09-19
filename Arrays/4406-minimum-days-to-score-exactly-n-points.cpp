class Solution {
public:
    int minDays(int n) {
        vector<long long> dp(n + 1, LLONG_MAX);
        dp[0] = 0;

        for(int i = 0; i <= n; i++) {
            if(dp[i] == LLONG_MAX)
                continue;
            long long sum = 0;
            for(int j = 1; j <= n; j++) {
                sum += j;
                if(i + sum > n)
                    break;
                // First streak: no skipped day needed
                if(i == 0)
                    dp[i + sum] = min(dp[i + sum], dp[i] + j);
                // Later streaks: one skipped day is needed
                else
                    dp[i + sum] = min(dp[i + sum], dp[i] + j + 1);
            }
        }
        return dp[n];
    }
};
