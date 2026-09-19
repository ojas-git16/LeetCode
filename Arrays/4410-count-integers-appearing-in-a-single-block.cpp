class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {\
        vector<bool> seen(101,false);
        vector<bool> invalid(101,false);
        
        for(int i=0; i<nums.size(); i++){
            if(seen[nums[i]] && nums[i]!=nums[i-1])
                invalid[nums[i]]=true;
            seen[nums[i]]=true;
        }
        int count = 0;
        for (int i = 1; i <= 100; i++) {
            if (seen[i] && !invalid[i])
                count++;
        }
        return count;
    }
};