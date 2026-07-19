class Solution {
public:

    bool canSplit(vector<int>& nums, int maxSum, int k) {

        int subarrays = 1;
        int sum = 0;

        for (int num : nums) {

            if (sum + num > maxSum) {
                subarrays++;
                sum = num;
            }
            else {
                sum += num;
            }
        }

        return subarrays <= k;
    }

    int splitArray(vector<int>& nums, int k) {

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low < high) {

            int mid = low + (high - low) / 2;

            if (canSplit(nums, mid, k))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};