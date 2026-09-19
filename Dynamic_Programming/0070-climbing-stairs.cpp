class Solution {
public:
    int climbStairs(int n) {
        int i=1, f1=1, f2=2, f3;
        if(n==1 || n==2)
                return n;
        for(int i=3; i<=n; i++)
        {
            f3=f1+f2;
            f1=f2;
            f2=f3;
        }
        return f3;
    }
};