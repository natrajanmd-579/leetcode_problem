class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];

        int prev1=0;
        int prev2=nums[0];

        for(int i=1;i<n;i++){
            int take=nums[i]+prev1;
            int notake=prev2;
            int curr=max(take,notake);

            prev1=prev2;
            prev2=curr;
        }
        return prev2;
    }
};