class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int s=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(int i=0; i<s; i++){
            int j=i;
            int first=intervals[i][0];
            int second=intervals[j][1];
            while(j<s-1 && second>=intervals[j+1][0]){
                j++;
                second=max(second, intervals[j][1]);
            }
            ans.push_back({first,second});
            i=j;
        }
        return ans;
    }
};