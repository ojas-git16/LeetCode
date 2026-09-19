class Solution {
public:
    int myAtoi(string s) {
        long x;
        int i=0;
        long sign = 1;
        while(i<s.size() && s[i]==' ')      i++;
        if(i==s.size())     return 0;

        if(s[i]=='-'){
            sign = -1;
            i++;
        }
        else if(s[i]=='+')
            i++;
        
        while(i<s.size() && s[i]>='0' && s[i]<='9'){
            x = x*10 + (s[i]-'0');
            if(x*sign > INT_MAX)        return INT_MAX;
            else if(x*sign < INT_MIN)   return INT_MIN;
            i++;
        }
        return (int)(sign * x);
    }
};