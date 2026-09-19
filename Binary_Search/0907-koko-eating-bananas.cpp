class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int banana;
        int maxm = 0;
        for (int i = 0; i < n; i++)
            maxm = max(piles[i], maxm);
        if (n == h)
            return maxm;

        int low = 1, high = maxm;
        while (low < high) {
            int hour=0;
            banana = low + (high - low) / 2;
            for(int i=0; i<n; i++){
                hour+=(piles[i]+banana-1)/banana;
                if(hour>h)   break;
            }
            if(hour>h)  low=banana+1;
            else  high=banana;
        }
        return high;
    }
};