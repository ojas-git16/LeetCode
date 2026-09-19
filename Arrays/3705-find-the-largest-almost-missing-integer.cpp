class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int largest = -1, maxm = -1, s = nums.size(), firlasmax = -1;
        unordered_map<int, int> freq;
        for (auto x : nums)
            freq[x]++;
        for (int i = 0; i < s; i++) {
            largest = max(largest, nums[i]);
            if (freq[nums[i]] == 1) {
                maxm = max(maxm, nums[i]);
                if (i == 0 || i == s - 1)
                    firlasmax = max(firlasmax, nums[i]);
            }
        }
        if (k == s)
            return largest;
        else if (k == 1)
            return maxm;
        else
            return firlasmax;
        return -1;
    }
};