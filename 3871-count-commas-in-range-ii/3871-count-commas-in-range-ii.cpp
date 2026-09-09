class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        long long start=1000;
        if(n < 1000){
            return 0;
        }
        long long count=1;
        while(start<=n){
            long long end=min(n,start*1000-1);
            ans+=(end-start+1)*count;
            start*=1000;
            count++;
        }
        return ans;
    }
};