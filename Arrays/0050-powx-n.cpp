class Solution {
public: 
    double myPow(double x, int n) {
        long long N = n;
        if(N==0) return 1;
        if(N<0){
            x=1/x;
            N=-N;
        }
        long long half=N/2;
        double ans=myPow(x,half);
        if(N%2==0) return ans*ans;
        else return x*ans*ans;
    }
};