class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int cnt=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(cnt>0){
                    res+=s[i];
                }
                cnt++;
            }
            else{
                cnt--;
                if(cnt>0){
                    res+=s[i];
                }
            }
        }
        return res;
    }
};