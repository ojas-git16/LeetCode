class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for (int num : nums)        sum += num;
        int target = sum - x;
        if (target < 0)         return -1;
        if (target == 0)         return nums.size();
        // Sliding window approach
        int i=0, j=0, len = -1;
        sum = 0;
        while(j < nums.size()){
            sum += nums[j++];
            while(sum > target)
                sum -= nums[i++];
            if(sum == target)
                len = max(len, j - i);
        }
        return (len == -1) ? -1 : nums.size() - len;
    }
};

// class Solution {
// public:
//     int minOperations(vector<int>& nums, int x) {
//         int sum = 0, len = -1;
//         for (int num : nums)
//             sum += num;
//         int target = sum - x;
//         if (target < 0)
//             return -1;
//         if(target == 0)
//             return nums.size();
//         unordered_map<int, int> mpp;
//         sum = 0;
//         mpp[0] = -1;
//         // we will find the max subarray whose sum == target
//         for (int i = 0; i < nums.size(); i++) {
//             sum += nums[i];
//             if (mpp.find(sum - target) != mpp.end())
//                 len = max(len, i - mpp[sum - target]);
//             if (mpp.find(sum) == mpp.end())
//                 mpp[sum] = i;
//         }
//         return (len == -1) ? -1 : nums.size() - len;
//     }
// };