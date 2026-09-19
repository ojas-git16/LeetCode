class Solution {
public:
    int totalMoney(int n) {
        int sum=0, i=1, cnt=0;
        while(n--){
            sum+=i++;
            cnt++;
            if(cnt==7){
                i-=6;
                cnt=0;
            }
        }
        return sum;
    }
};