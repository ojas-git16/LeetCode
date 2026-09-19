class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int freq = 0;

        long long sum = 0;

        for(int left = 0, right = 0; right < nums.size(); right++) {

            sum += nums[right];

            while(sum + k < 1LL * nums[right] * (right - left + 1)) {

                sum -= nums[left];
                left++;
            }

            freq = max(freq, right - left + 1);
        }

        return freq;
    }
};