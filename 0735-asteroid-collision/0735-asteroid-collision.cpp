class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int x:asteroids){
            bool alive=true;
            while(alive && !st.empty() && st.top()>0 && x < 0){
                if(abs(st.top())<abs(x)){
                    st.pop();
                    continue;
                }
                else if(abs(st.top())==abs(x)){
                    st.pop();
                }
                alive=false;
            }
            if(alive){
                st.push(x);
            }
        }
        vector<int>res(st.size());
        for(int i=st.size()-1;i>=0;i--){
            res[i]=st.top();
            st.pop();
        }
        return res;
    }
};