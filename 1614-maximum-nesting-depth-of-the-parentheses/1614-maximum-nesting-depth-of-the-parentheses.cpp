class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0;
        int cnt = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                cnt++;
                maxDepth = max(maxDepth, cnt);
            } 
            else if (s[i] == ')') {
                cnt--;
            }
        }
        return maxDepth;
    }
};
