class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i;
        int n;
        n=nums.size();
        vector<int>rear(n,0);
        int pn=0;
        int nn=1;
        for(i=0;i<n;i++)
        {
            if(nums[i]>0){
              rear[pn]=nums[i];
              pn=pn+2;
            }
            else{
              rear[nn]=nums[i];
              nn=nn+2;
            }
        }
        return rear;
    }
};