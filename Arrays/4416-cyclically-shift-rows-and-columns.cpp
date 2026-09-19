class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        for(int i = 0; i < n; i++) {
            vector<int> temp(n);
            int k = rowShift[i];
            for(int j = 0; j < n; j++) 
                temp[j] = grid[i][(j + k + n) % n];

            grid[i] = temp;
        }
        for(int j = 0; j < n; j++) {
            vector<int> temp(n);
            int k = colShift[j];
            for(int i = 0; i < n; i++)
                temp[i] = grid[(i + k + n) % n][j];

            for(int i = 0; i < n; i++) {
                grid[i][j] = temp[i];
            }
        }
        return grid;
    }
};