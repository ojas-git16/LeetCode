class Solution {
public:
    bool checkZeroOnes(string s) {
        int c1 = 0, c2 = 0, m1 = 0, m2 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0')
                c1 = 0;
            else
                c1++;
            m1 = max(c1, m1);

            if (s[i] == '1')
                c2 = 0;
            else
                c2++;
            m2 = max(m2, c2);
        }

        if (m1 > m2)
            return true;
        return false;
    }
};