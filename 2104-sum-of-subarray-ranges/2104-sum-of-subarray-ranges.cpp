class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long maxsum=0,minsum=0;
        int mid,left,right;
        long long count;
        stack<int>st;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || nums[st.top()] > nums[i])){
                mid=st.top();
                st.pop();
                left=st.empty()?-1:st.top();
                right=i;
                count=(mid-left)*(right-mid);
                minsum+=count*nums[mid];
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || nums[st.top()] < nums[i])){
                mid=st.top();
                st.pop();
                left=st.empty()?-1:st.top();
                right=i;
                count=(mid-left)*(right-mid);
                maxsum+=count*nums[mid];
            }
            st.push(i);
        }
        return maxsum-minsum;
    }
};