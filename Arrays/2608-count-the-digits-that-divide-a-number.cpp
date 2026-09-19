class Solution {
public:
    int countDigits(int num) {
        int x=num,i=0;
        while(x!=0)
        {
            if(num%(x%10)==0)
                i++;
            x/=10;
        }
        return i;
    }
};