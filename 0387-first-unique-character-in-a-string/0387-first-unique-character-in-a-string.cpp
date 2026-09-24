class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>freq(26);
        for(char c:s){
            freq[c]++;
        }

        for(int i=0;i<s.length();i++){
            if(freq[s[i]]==1){
                return i;
                break;
            }
        }
        return -1;
    }
};