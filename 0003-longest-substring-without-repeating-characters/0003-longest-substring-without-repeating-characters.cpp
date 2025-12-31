class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int left=0,right=0,maxlen=0;
        while(right<s.length()){
            if(st.find(s[right])==st.end()){
                st.insert(s[right]);
                maxlen=max(maxlen,right-left+1);
                right++;
            }
            else{
                st.erase(s[left]);
                left++;
            }
        }
        return maxlen;
    }
};