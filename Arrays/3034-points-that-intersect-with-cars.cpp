// TC - O(1)
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        bool covered[101] = {};
        for (auto& x : nums)
            for (int p = x[0]; p <= x[1]; p++)
                covered[p] = true;

        return count(covered, covered + 101, true);
    }
};

// TC - O(n)
// class Solution {
// public:
//     int numberOfPoints(vector<vector<int>>& nums) {
//         int n=nums.size(), count=0;
//         sort(nums.begin(),nums.end());
//         for(int i=0; i<n; i++){
//             int j=i;
//             int maxel=nums[i][1];
//             while(j+1<nums.size() && maxel>=nums[j+1][0]){
//                 maxel=max(maxel,nums[j+1][1]);
//                 j++;
//             }
//             count+=maxel-nums[i][0]+1;
//             i=j;
//         }
//         return count;
//     }
// };