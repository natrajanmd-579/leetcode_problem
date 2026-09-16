class Solution {
public:
    const long long MOD=1e9+7;
    long long power(long long a,long long b){
        long long res=1;
        while(b>0){
            if(b%2!=0){
                res=res*a%MOD;
            }
            a=a*a%MOD;
            b=b/2;
        }
        return res;
    }
    int numberOfSets(int n, int k) {
        int r=2*k;
        long long ans=1;
        for(int i=1;i<=r;i++){
            ans=ans*(n+k-i)%MOD;
            ans=ans*power(i,MOD-2)%MOD;
        }
        return ans;
    }
};