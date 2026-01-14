class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int maxlen=0;
        int n=heights.size();
        for(int i=0;i<=n;i++){
            int curhei=(i==n)?0:heights[i];
            while(!st.empty() && curhei < heights[st.top()]){
                int height=heights[st.top()];
                st.pop();
                int width;
                if(st.empty()) width=i;
                else width=i-st.top()-1;
                maxlen=max(maxlen,height*width);
            }
            st.push(i);
      }
      return maxlen;
    }
};