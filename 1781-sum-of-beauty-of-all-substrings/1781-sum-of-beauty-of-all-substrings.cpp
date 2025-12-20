class Solution {
public:
    int beautySum(string s) {
        int beauty=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            for(int j=i;j<n;j++){
                 freq[s[j]-'a']++;

                 int maxfreq=0;
                 int minfreq=INT_MAX;
                 for(int k=0;k<26;k++){
                      if(freq[k]>0){
                      maxfreq=max(maxfreq,freq[k]);
                      minfreq=min(minfreq,freq[k]);}
                 }
                 beauty+=(maxfreq-minfreq);
            }
        }
        return beauty;
    }
};