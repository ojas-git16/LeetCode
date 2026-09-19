class Solution {
public:
    int fib(int n) {
        if(n==1 or n==0)
            return n;
        else
            return fib(n-2)+fib(n-1);
    }
};