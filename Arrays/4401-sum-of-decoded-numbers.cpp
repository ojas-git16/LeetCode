class Solution {
public:
    
    long long MOD = 1e9 + 7;
    long long power(long long x, long long y) {
        long long ans = 1;
        while(y) {
            if(y%2 == 1)
                ans = (ans * x) % MOD;
            x = (x * x) % MOD;
            y /= 2;
        }

        return ans;
    }
    int sumDecoded(vector<long long>& nums) {
        long long ans = 0;
        for(int i=0; i<nums.size(); i++){
            long long wid = nums[i] % 10;
            long long d = nums[i] / 10;
            long long x = d;
            long long cnt = 0;
            while(x>0){
                x/=10;
                cnt++;
            }
            long long p = 1;
            for(int j = 0; j < cnt - wid; j++)
                p *= 10;

            x = d / p;
            long long y = d % p;
            ans +=  power(x,y);
            ans %= MOD;
        }
        return ans;
    }
};