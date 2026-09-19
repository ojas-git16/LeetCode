class Solution {
public:
    bool isPalindrome(int x) {
    int c[100], len=0;
    if(x<0)
    return false;
    for(int i=0; ;i++){
        c[i]=x%10;
        len++;
        x=x/10;
        if(x==0)
        break;        
    }
    for(int i=0;i<(len/2);i++)
    {
        if (c[i]==c[len-i-1])
        continue;
        else
        return false;
    }
    return true;
}
};