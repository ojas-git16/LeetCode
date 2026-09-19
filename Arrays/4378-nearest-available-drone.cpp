class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans = INT_MAX, idx = -1;
        for(int i=0; i<drones.size(); i++){
            int dist = (abs(target[0]-drones[i][0]) + abs(target[1]-drones[i][1]));
            if(drones[i][2] >= dist && ans>dist){
                ans = dist;
                idx = i;
            }
        }
        return idx;
    }
};