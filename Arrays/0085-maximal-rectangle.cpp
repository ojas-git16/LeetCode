class Solution {
public:
    vector<int> ps(vector<int>& v) {
        vector<int> ans(v.size(), -1);
        stack<int> st;
        for (int i = 0; i < v.size(); i++) {
            while (!st.empty() && v[st.top()] > v[i])
                st.pop();
            if (!st.empty())
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> ns(vector<int>& v) {
        vector<int> ans(v.size(), v.size());
        stack<int> st;
        for (int i = v.size() - 1; i >= 0; i--) {
            while (!st.empty() && v[st.top()] >= v[i])
                st.pop();
            if (!st.empty())
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int area(vector<int>& heights) {
        vector<int> nsi = ns(heights);
        vector<int> psi = ps(heights);

        int maxarea = 0;
        for (int i = 0; i < heights.size(); i++)
            maxarea =
                max(maxarea, ((nsi[i] - i) + (i - psi[i]) - 1) * heights[i]);
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxarea = 0;
        vector<int> v(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1')
                    v[j]++;
                else
                    v[j] = 0;
            }
            maxarea = max(maxarea, area(v));
        }
        return maxarea;
    }
};