class Solution {
public:
    void func(vector<vector<int>> &ans, vector<int> &arr, vector<int> temp, int target, int idx, int n, int sum){
        if(sum > target)        return;
        if(sum == target){
            ans.push_back(temp);
            return;
        }
        if(idx == n)    return;
        func(ans, arr, temp, target, idx+1, n, sum);
        temp.push_back(arr[idx]);
        sum+=arr[idx];
        func(ans, arr, temp, target, idx, n, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        func(ans, candidates, temp, target, 0, n, 0);
        return ans;
    }
};