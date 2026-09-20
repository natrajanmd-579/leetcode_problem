class Solution {
public:
    int reverseDegree(string s) {
        int product=1;
        int sum=0;
        for(int i=0;i<s.length();i++){
            product=(i+1)*('z'-s[i]+1);
            sum+=product;
        }
        return sum;
    }
};