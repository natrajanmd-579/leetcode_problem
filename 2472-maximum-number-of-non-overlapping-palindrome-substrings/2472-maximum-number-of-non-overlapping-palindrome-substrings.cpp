class Solution {
public:
    int maxPalindromes(string s, int k) {
        int size=s.length();
        vector<bool>pal(size,false);
        int ans=0;
        int lastend=-1;
        for(int r=0;r<size;r++){
             bool prev=true;
            for(int l=r;l>=0;l--){
                bool old=pal[l];
                int len=r-l+1;
                if(s[r]==s[l] && (len <=2 || prev)){
                    pal[l]=true;
                    if(len >=k && l> lastend){
                        ans++;
                        lastend=r;
                    }
                }
                else{
                    pal[l]=false;
                }
                prev=old;
            }
        }
        return ans;
    }
};