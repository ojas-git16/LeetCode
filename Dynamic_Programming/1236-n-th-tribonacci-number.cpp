class Solution {
public:
    int tribonacci(int n) {
        int f0=0, f1=1, f2=1, f3;
        if(n==0 || n==1)
            return n;
        if(n==2)
            return 1;
        for(int i=3; i<=n; i++)
        {
            f3=f0+f1+f2;
            f0=f1;
            f1=f2;
            f2=f3;
        }
        return f3;
    }
};