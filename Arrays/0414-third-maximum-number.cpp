class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max1 = LLONG_MIN;
        long long max2 = LLONG_MIN;
        long long max3 = LLONG_MIN;
        for(int num : nums) {
            if(num == max1 || num == max2 || num == max3)
                continue;
            if(num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if(num > max2) {
                max3 = max2;
                max2 = num;
            }
            else if(num > max3)
                max3 = num;
        }
        return (max3 == LLONG_MIN) ? max1 : max3;
    }
};

// class Solution {
// public:
//     int thirdMax(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int n=nums.size(), cnt=2;
//         for(int i=n-1; i>0; i--){
//             if(nums[i-1]!=nums[i])
//                 cnt--;
//             if(cnt==0)
//                 return nums[i-1];
//         }
//         return nums[n-1];
//     }
// };
