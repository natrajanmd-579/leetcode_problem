class Solution {
public:
    int numberOfSubstrings(string s) {
        int right=0,left=0;
        int n=s.size();
        int res=0;
        int count[3]={0,0,0};
        while(right<n){
            count[s[right]-'a']++;
            while(count[0]>0 && count[1]>0 && count[2]>0){
                res+=(n-right);
                count[s[left]-'a']--;
                left++;
            }
            right++;
        }
        return res;
    }
};