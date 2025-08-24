class Solution {
public:
    int singleNumber(vector<int>& nums) {
          int n = nums.size();
    int j = 0;
    for (int i = 0; i < n; i++) {
        j = j ^ nums[i];
    }
    return j;
}
    
};
