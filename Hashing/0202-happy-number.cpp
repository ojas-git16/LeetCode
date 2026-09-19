class Solution {
public:
    bool isHappy(int n) {
            int x = n, ans = 11, d;
    while (ans >= 10)
    {
        ans = 0;
        while (x != 0)
        {
            d = x % 10;
            x = x / 10;
            ans += (d * d);
        }
        x=ans;
    }
    if (ans == 1 || ans == 7)
        return true;
    else if (ans >= 2 && ans <= 9)
        return false;
    return false;
    }
};