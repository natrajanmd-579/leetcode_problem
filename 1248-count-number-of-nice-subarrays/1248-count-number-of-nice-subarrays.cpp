class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int result=0,presum=0;
        unordered_map<int,int>count;
        count[0]=1;
        for(int i=0;i<nums.size();i++){
                if(nums[i]%2==1)
                    presum+=1;
                if(count.find(presum-k)!=count.end()){
                    result+=count[presum-k];
                }  
                count[presum]++;    
        }
        return result;
    }
};