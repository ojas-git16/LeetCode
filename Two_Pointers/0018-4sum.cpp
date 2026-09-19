class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector <vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; ){
            for(int j=i+1; j<n; ){
                long long sum = 0;
                int k=j+1, l=n-1;
                while(k<l){
                    sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++; l--;
                        while(l>k && nums[l+1]==nums[l])
                            l--;
                        while(k<l && nums[k-1]==nums[k])
                            k++;
                    }
                    else if(sum>target){
                        l--;
                        while(l>k && nums[l+1]==nums[l])
                            l--;
                    }
                    else if(sum<target){
                        k++;
                        while(k<l && nums[k-1]==nums[k])
                            k++;
                    }
                }
                j++;
                while(j<n && nums[j-1]==nums[j])
                    j++;
            }
            i++;
            while(i<n && nums[i-1]==nums[i])
                i++;
        }
        return ans;
    }
};