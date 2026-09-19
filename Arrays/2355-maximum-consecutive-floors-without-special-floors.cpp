class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int max=special[0]-bottom;
        max=(top-special[special.size()-1]>max)?top-special[special.size()-1]:max;
        for(int i=1; i<special.size(); i++)
            if(special[i]-special[i-1]-1>max)
                max=special[i]-special[i-1]-1;
        return max;
    }
};