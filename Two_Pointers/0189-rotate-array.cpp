class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k<=nums.size())
        {
            vector <int> temp(nums.end()-k,nums.end());
            nums.erase(nums.end()-k,nums.end());
            nums.insert(nums.begin(), temp.begin(), temp.end());
        }
        else
        for(int i=0; i<k; i++)
        {
            int v=nums[nums.size()-1];
            nums.erase(nums.end()-1);
            nums.insert(nums.begin(),v);
            
        }
    }
};