class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxm=0,cand=0;
        vector <int> v(100001,0);
        for(int x : costs){
            maxm=max(maxm,x);
            v[x]++;
        }
        for(int i=1; i<=maxm; i++){
            if(v[i]==0)
                continue;
            while((coins-i)>=0 && v[i]>0){
                cand++;
                coins-=i;
                v[i]--;
            }
        }
        return cand;
    }
};