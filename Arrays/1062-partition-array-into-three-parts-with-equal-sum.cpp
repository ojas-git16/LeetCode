class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        for(int num : arr)
            sum += num;
        if(sum%3 != 0)
            return false;
        int target = sum / 3;
        sum = 0;
        int cnt = 0;
        for(int i=0; i<arr.size(); i++){
            sum += arr[i];
            if(sum == target){
                cnt ++;
                sum = 0;
            }
        }
        if(cnt >= 3)
            return true;
        return false;
    }
};