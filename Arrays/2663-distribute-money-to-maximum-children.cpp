// TC - O(1)
class Solution {
public:
    int distMoney(int money, int children) {
        if((money==4 && children==1) || money<children)
            return -1;
        money-=children;  //gave everyone 1 dollar
        int count=min(children,money/7);
        money=money-(count*7);

        if((money>0 && count==children) || (money==3 && count+1==children))
            count--;
        return count;

    }
};


// TC - O(n)    
// class Solution {
// public:
//     int distMoney(int money, int children) {
//         if((money==4 && children==1) || money<children)
//             return -1;
//         money-=children;  //gave everyone 1 dollar
//         int count=0;
//         while(money-7>=0 && count+1<children){
//             money-=7;
//             count++;
//         }
//         if(money==7 && children==count+1)
//             count++;
//         if(money==3 && count+1==children)
//             count--;
//         return count;
//     }
// };