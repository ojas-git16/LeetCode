class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int time=0, n=timeSeries.size();
        for(int i=0, j=1; i<n-1 && j<n; i++, j++)
        {
            if(timeSeries[i]+duration<=timeSeries[j])
                time+=duration;
            else
                time+=timeSeries[j]-timeSeries[i];
        }
        time+=duration; //for last element
        return time;
    }
};