class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
        int arr1[30]={0};
//        int arr2[30]={0};
        int len=s.length();
        for(int i=0;i<len;i++)
        {
            arr1[s[i]-97]++;
//            arr2[t[i]-97]++;
            arr1[t[i]-97]--;
        }
        for(int i=0; i<30; i++)
        {
//            if(arr1[i]!=arr2[i])
            if(arr1[i]!=0)
                return false;
        }
        return true;
    }
};