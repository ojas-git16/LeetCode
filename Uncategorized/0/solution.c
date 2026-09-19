/*
 * Platform: LeetCode
 * Problem: 0
 * URL: https://leetcode.com/submissions/detail/2139646368/
 * Language: C
 * Difficulty: Medium
 * Topics: Uncategorized
 * Runtime: 222 ms
 * Memory: 293.92 MB
 * Synced: 2026-09-19T13:02:35.797Z
 */

1class Solution {
2public:
3    int countSpecialIntegers(vector<int>& nums) {
4        unordered_map<int, vector<int>> v;
5        for(int i = 0; i < nums.size(); i++)
6            v[nums[i]].push_back(i);
7        int ans = 0;
8        for(auto &it : v) {
9            vector<int> &idx = it.second;
10            if(idx.size() < 3)
11                continue;
12            int gap = idx[1] - idx[0];
13            bool sp = true;
14            for(int i = 2; i < idx.size(); i++) 
15                if(idx[i] - idx[i - 1] != gap) {
16                    sp = false;
17                    break;
18                }
19            if(sp)    ans++;
20        }
21        return ans;
22    }
23};
