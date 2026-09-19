class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long mypow(long long x, long long n) {
        if(n == 0)      return 1;
        long long ans = mypow(x, n / 2);
        ans = (ans * ans) % MOD;
        if(n % 2)
            ans = (ans * x) % MOD;
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;
        // odd - 4^odd, even - 5^even
        long long a = mypow(4, odd);
        long long b = mypow(5, even);
        return (a*b)%MOD;
    }
};