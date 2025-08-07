class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return; 
    k = k % n;
    vector<int> temp(n);
    for (int i = 0; i < n; i++) {
       temp[i]=nums[(i+n-k) % n] ;
    }
    nums = temp;
    }
};