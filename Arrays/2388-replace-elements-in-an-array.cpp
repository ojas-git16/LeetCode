class Solution {
public:
    vector<int> arrayChange(vector<int>& arr, vector<vector<int>>& op) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < arr.size(); i++)
            mpp[arr[i]] = i;
        for (auto i : op) {
            arr[mpp[i[0]]] = i[1]; // replace value to its index
            mpp[i[1]] = mpp[i[0]]; // update new value with its index
        } 
        return arr;
    }
};