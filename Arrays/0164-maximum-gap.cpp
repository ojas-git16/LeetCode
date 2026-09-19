class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int max = 0;
        if (nums.size() < 2)
            return 0;
        else {
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size() - 1; i++)
                if ((nums[i + 1] - nums[i]) > max)
                    max = nums[i + 1] - nums[i];
        }
        return max;
    }
};