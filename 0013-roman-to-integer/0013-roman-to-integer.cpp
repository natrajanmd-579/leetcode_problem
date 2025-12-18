class Solution {
public:
    int romanToInt(string s) {
        int cur=0;
        int total=0;
        int prev=0;
      for(int i=s.length()-1;i>=0;i--){
        if(s[i]=='I') cur=1;
        else if(s[i]=='V') cur=5;
        else if(s[i]=='X') cur=10;
        else if(s[i]=='L') cur=50;
        else if(s[i]=='C') cur=100;
        else if(s[i]=='D') cur=500;
        else cur=1000;

        if(cur < prev){
            total-=cur;
        }
        else total+=cur;

        prev=cur;
        }
        return total;
      }  
};