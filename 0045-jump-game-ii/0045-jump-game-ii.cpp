class Solution {
public:
    int jump(vector<int>& nums) {
       int jump=0;
       int nojump=0;
       int curend=0;
       for(int i=0;i<nums.size()-1;i++){
           jump=max(jump,i+nums[i]);
           if(i==curend){
              nojump++;
              curend=jump;
           }
       } 
       return nojump;
    }
};