class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int right=0,left=0,maxlen=0;
        int count=0;
        while(right<nums.size()){
            if(nums[right]==0){
                count++;
            }
            while(k<count){
                if(nums[left]==0)
                    count--;
                left++;    
            }   
            maxlen=max(maxlen,right-left+1);
            right++;
        }
        return maxlen;
    }
};