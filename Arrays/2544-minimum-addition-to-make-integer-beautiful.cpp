class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        long long x = 0;
        long long i = 10;
    lable:
        long long num = n;
        int count = 0;
        while (num != 0) {
            count += num % 10;
            num /= 10;
        }
        if (count <= target)
            return x;
        x += i - (n % i);
        n += i - (n % i);
        i *= 10;
        goto lable;
    }
};