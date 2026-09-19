class Solution {
public:
    void func(vector<vector<int>> &ans, vector<int> &arr, vector<int> temp, int target, int idx, int n, int sum){
        if(sum > target)        return;
        if(sum == target){
            ans.push_back(temp);
            return;
        }
        if(idx == n)    return;
        for(int i = idx; i < n; i++){
            if(i > idx && arr[i] == arr[i-1])
                continue;
            if(sum + arr[i] > target)
                break;
            temp.push_back(arr[i]);
            func(ans, arr, temp, target, i+1, n, sum + arr[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end()); 
        vector<vector<int>> ans;
        vector<int> temp;
        func(ans, candidates, temp, target, 0, n, 0);
        return ans;
    }
};