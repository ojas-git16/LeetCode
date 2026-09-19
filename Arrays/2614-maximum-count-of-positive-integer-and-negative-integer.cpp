class Solution {
public:
    int maximumCount(vector<int>& arr) {

        int low = 0, high = arr.size() - 1;
        int firstNonNegative = arr.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= 0) {
                firstNonNegative = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        int negCount = firstNonNegative;

        low = 0, high = arr.size() - 1;
        int firstPositive = arr.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] > 0) {
                firstPositive = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        int posCount = arr.size() - firstPositive;
        int ans = (posCount>negCount) ? posCount : negCount;
        return ans;
    }
};