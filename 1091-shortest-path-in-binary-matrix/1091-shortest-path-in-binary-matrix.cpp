class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]==1) return -1;
        if(grid[m-1][n-1]==1) return -1;
        queue<pair<pair<int,int>,int>>q;

        q.push({{0,0},1});
        grid[0][0]=1;

        vector<int>dx={-1,-1,-1,0,0,1,1,1};
        vector<int>dy={-1,0,1,-1,1,-1,0,1};

        while(!q.empty()){
             auto node=q.front();
             q.pop();
             int x=node.first.first;
             int y=node.first.second;
             int dist=node.second;
             if(x==m-1 && y==n-1) return dist;
             for(int i=0;i<8;i++){
             int nx=x+dx[i];
             int ny=y+dy[i];
              if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==0){
                 grid[nx][ny]=1;
                 q.push({{nx,ny},dist+1});
              }
             }
        }
       return -1;
    }
};