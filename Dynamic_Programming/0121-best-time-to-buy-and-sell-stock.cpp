class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minel=prices[0], profit=0;
        for(int i=1; i<prices.size(); i++)
        {
            int gain=prices[i]-minel;
            profit=max(profit,gain);
            minel=min(minel,prices[i]);
        }
        return profit;
    }
};