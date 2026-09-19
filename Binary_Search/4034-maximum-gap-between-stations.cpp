class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size();
        vector<int> left(n), right(n);
        int p = 0;
        for (int i = 0; i < n; i++) {
            while (station[p] != skill[i])
                p++;
            left[i] = p++;
        }
        p = station.size() - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (station[p] != skill[i])
                p--;
            right[i] = p--;
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, right[i + 1] - left[i]);
        }
        return ans;
    }
};