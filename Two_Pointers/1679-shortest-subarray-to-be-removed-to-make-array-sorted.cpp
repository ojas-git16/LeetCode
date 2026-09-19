class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low + 1 < n && arr[low] <= arr[low + 1])
            low++;
        while (high - 1 >= 0 && arr[high - 1] <= arr[high])
            high--;

        if (low >= high) return 0;  // already sorted

        int ans = min(n - low - 1, high);  // remove just suffix or just prefix

        int b = high;
        for (int a = 0; a <= low; a++) {
            while (b < n && arr[b] < arr[a])
                b++;
            ans = min(ans, b - a - 1);
        }

        return ans;
    }
};