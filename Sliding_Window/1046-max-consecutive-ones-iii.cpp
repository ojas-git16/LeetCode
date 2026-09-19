class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int i=0, j=0;
        int cnt = k;
        while(j<nums.size()){
            if(nums[j]==1)
                j++;
            else{
                if(cnt>0){
                    j++;
                    cnt--;
                }
                else{
                    if(nums[i]==0){
                        cnt--;
                        i++;
                        j++;
                    }
                    else i++;
                }
            }
            ans = max(ans, j-i);
        }
        return ans;
    }
};