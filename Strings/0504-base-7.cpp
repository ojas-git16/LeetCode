class Solution {
public:
    string convertToBase7(int num)
{
    int u = (num < 0) ? -num : num;
    int x = 0, place = 1;
    string z;
    while (u != 0)
    {
        int digit = u % 7;
        x = x + (digit * place);
        u = u / 7;
        place *= 10;
    }
    x = (num < 0) ? -x : x;
    z = to_string(x);
    return z;
} 
};