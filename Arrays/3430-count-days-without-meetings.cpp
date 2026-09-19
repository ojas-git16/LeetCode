class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size(), count=days;
        sort(meetings.begin(),meetings.end());
        for(int i=0; i<n; i++){
            int j=i;
            int maxel=meetings[j][1];
            while(j<n-1 && maxel>=meetings[j+1][0]){
                maxel=max(maxel,meetings[j+1][1]);
                j++;
            }
            count=count-(maxel-meetings[i][0]+1);
            i=j;
        }
        return count;
    }
};