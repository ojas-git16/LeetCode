class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set <int> st;
        int n=grid.size(), incr=1;
        int num;
        long long sum=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                sum+=incr++;
                sum-=grid[i][j];
                int sz=st.size();
                st.insert(grid[i][j]);
                if(sz==st.size())
                    num=grid[i][j];
            }
        }
        sum+=num;
        return {num,(int)sum};
    }
};