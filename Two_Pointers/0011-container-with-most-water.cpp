// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int n=height.size(),i,j;
//         int a=height[0],b=height[n-1],ar, max=0;
//         for (i = 1; i<n; i++) {
//             if(height[i]>=a+1)
//                 a=height[i];
//             else break;
//         }
//         for (j = n-2; j>=0; j--) {
//             if(height[j]>=b+1)
//                 b=height[j];
//             else break;
//         }
//         return min(a,b)*(j-i+2);
//     }
// };
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ar, max = 0, n = height.size(), i=0, j=n-1;
        while( i < j) {
            ar = min(height[i], height[j]) * (j - i);
            if (max < ar)
                max = ar;
            (height[i] > height[j]) ? j-- : i++;
        }
        return max;
    }
};