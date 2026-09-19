class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        // {value, frequency}
        stack<pair<int, int>> st;
        long long ans = 0;      
        long long total = 0;    // sum of all freq in stack ie. number of possible pairs
        for(int x : nums) {
            // Values greater than x can never be used again
            while(!st.empty() && st.top().first > x){
                total -= st.top().second;
                st.pop();
            }

            // Count values strictly smaller than x
            if(!st.empty() && st.top().first == x)      ans += total - st.top().second;
            else        ans += total;

            // Insert x
            if(!st.empty() && st.top().first == x)          st.top().second++;
            else           st.push({x, 1});
            total++;
        }
        return ans;
    }
};