class Solution {
public:
    int nextGreaterElement(int n) {

        string s = to_string(n);

        if(!next_permutation(s.begin(), s.end()))
            return -1;

        // for integer overflow of next permutation
        long long x = stoll(s);  // string to long long just like stoi

        return (x > INT_MAX) ? -1 : x;
    }
};