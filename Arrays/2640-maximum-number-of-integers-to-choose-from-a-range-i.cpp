// TC = O(n)
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set <int> ban(banned.begin(),banned.end());  // avg SC = O(n)
        int sum=0, count=0;

        for(int i=1; i<=n; i++){
            if(ban.find(i)!=ban.end()) // OR set.count() returns 0/1 OR set.contains() - returns true/false
                continue;
            else{
                sum+=i;
                if(sum>maxSum)
                    return count;
                count++;
            }
        }
        return count;
    }
};


// TC - O(nlogn + b)
// class Solution {
// public:
//     int maxCount(vector<int>& banned, int n, int maxSum) {
//         sort(banned.begin(), banned.end());      //O(nlogn)
//         int size=banned.size(), sum=0, count=0, num=1, i=0;
//         while(num<=n){
//             if(i<size && num==banned[i]){
//                 while(i<size && banned[i]==num)
//                     i++;
//                 num++;
//             }
//             else{
//                 sum+=num;
//                 if(sum>maxSum)
//                     return count;
//                 num++;
//                 count++;
//             }
//         }
//         return count;
//     }
// };