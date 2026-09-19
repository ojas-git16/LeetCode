class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s=flowerbed.size(), count=0;
        for(int i=0; i<s; i++)
            if((flowerbed[i]==0) && ((i==0 && s>1 && flowerbed[i+1]==0) || (i==s-1 && s>1 && flowerbed[i-1]==0) || (i>0 && i<s-1 && flowerbed[i-1]==0 && flowerbed[i+1]==0) || (i==0 && s==1))){
                count++;
                i++;
            }
        if(count>=n)
            return true;
        return false;
    }
};