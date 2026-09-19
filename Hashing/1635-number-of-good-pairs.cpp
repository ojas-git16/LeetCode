class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map <int,int> mpp;
        int pairs=0;
        for(int num : nums){
            pairs+=mpp[num];
            mpp[num]++;
        }
        return pairs;
    }
};