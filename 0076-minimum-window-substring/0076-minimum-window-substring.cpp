class Solution {
public:
    string minWindow(string s, string t) {
        int left=0,right=0,minlen=INT_MAX;
        unordered_map<char,int>need,window;
        for(char c:t) need[c]++;
        int needcnt=need.size(),have=0;
        int start=0;
        while(right<s.length()){
            char c=s[right];
            window[c]++;
            if(need.count(c)&&window[c]==need[c]){
                have++;
            }
            while(have==needcnt){
                if(right-left+1<minlen){
                    minlen=right-left+1;
                    start=left;
                }
                char l=s[left];
                window[l]--;
                if(need.count(l)&&window[l]<need[l]){
                    have--;
                }
                left++;
            }
            right++;
        }
        return minlen==INT_MAX?"":s.substr(start,minlen);
    }
};