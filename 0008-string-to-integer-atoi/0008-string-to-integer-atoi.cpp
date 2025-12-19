class Solution {
public:
    int myAtoi(string s) {
        long long num = 0;        
        int sign = 1;       
        bool start = false; 
        for (int i = 0; i < s.length(); i++) {
            if (!start && s[i] == ' ') {
                continue;
            }
            if (!start && (s[i] == '+' || s[i] == '-')) {
                if (s[i] == '-') sign = -1;
                start = true;
                continue;
            }
            if (s[i] >= '0' && s[i] <= '9') {
                start = true;
                num = num * 10 + (s[i] - '0');
            }
            else {
                break; 
            }
        }
        return num * sign;
    }
};
