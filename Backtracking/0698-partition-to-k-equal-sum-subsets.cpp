class Solution {
public:
    bool func(vector<int>& nums, vector<bool>& used, int target, int k,
              int sum, int start) {

        if(k == 1)
            return true;

        if(sum == target)
            return func(nums, used, target, k - 1, 0, 0);

        for(int i = start; i < nums.size(); i++) {

            if(used[i])
                continue;

            // Skip duplicate choices at the same level
            if(i > start && nums[i] == nums[i - 1] && !used[i - 1])
                continue;

            if(sum + nums[i] > target)
                continue;

            used[i] = true;

            if(func(nums, used, target, k, sum + nums[i], i + 1))
                return true;

            used[i] = false;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size(), target, sum = 0;

        for(int i = 0; i < n; i++)
            sum += nums[i];

        if(sum % k != 0)
            return false;

        target = sum / k;

        sort(nums.rbegin(), nums.rend());

        if(nums[0] > target)
            return false;

        vector<bool> used(n, false);

        return func(nums, used, target, k, 0, 0);
    }
};