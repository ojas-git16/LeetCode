class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> v;
        for(int i = 0; i < nums.size(); i++)
            v[nums[i]].push_back(i);
        int ans = 0;
        for(auto &it : v) {
            vector<int> &idx = it.second;
            if(idx.size() < 3)
                continue;
            int gap = idx[1] - idx[0];
            bool sp = true;
            for(int i = 2; i < idx.size(); i++) 
                if(idx[i] - idx[i - 1] != gap) {
                    sp = false;
                    break;
                }
            if(sp)    ans++;
        }
        return ans;
    }
};