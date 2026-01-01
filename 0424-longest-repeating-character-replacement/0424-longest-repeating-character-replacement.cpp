class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,right=0,maxlen=0,maxfreq=0;
        vector<int>freq(26,0);
        while(right<s.length()){
            freq[s[right]-'A']++;
            maxfreq=max(maxfreq,freq[s[right]-'A']);
            while((right-left+1)-maxfreq>k){
                freq[s[left]-'A']--;
                left++;
            }
            maxlen=max(maxlen,right-left+1);
            right++;
        }
        return maxlen;
    }
};