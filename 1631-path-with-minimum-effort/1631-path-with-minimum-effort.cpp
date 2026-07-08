class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();

        priority_queue<
             pair<int,pair<int,int>>,
             vector<pair<int,pair<int,int>>>,
             greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));
        vector<int>dx={-1,1,0,0};
        vector<int>dy={0,0,-1,1};
        effort[0][0]=0;

        while(!pq.empty()){
            auto node=pq.top();
            pq.pop();
            int curreffort=node.first;
            int x=node.second.first;
            int y=node.second.second;
            if(x==m-1 && y==n-1){
                return curreffort;
            }
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<m && ny<n){
                    int diff=abs(heights[x][y]-heights[nx][ny]);
                    int neweffort=max(curreffort,diff);
                    if(neweffort < effort[nx][ny]){
                        effort[nx][ny]=neweffort;
                        pq.push({neweffort,{nx,ny}});
                    }
                }
            }
        }
    return 0;
    }
};