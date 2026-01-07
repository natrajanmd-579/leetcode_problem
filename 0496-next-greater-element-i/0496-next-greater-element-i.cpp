class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>nextgt;
        stack<int>st;
        for(int num:nums2){
                while(!st.empty() && num>st.top()){
                    nextgt[st.top()]=num;
                    st.pop();
                }
                st.push(num);
        }
        while(!st.empty()){
            nextgt[st.top()]=-1;
            st.pop();
        }
        vector<int>res;
        for(int num:nums1){
            res.push_back(nextgt[num]);
        }
        return res;
    }
};