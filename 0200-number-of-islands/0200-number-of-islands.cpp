class Solution {
public:
    vector<int>dx={-1,1,0,0};
    vector<int>dy={0,0,-1,1};

    void dfs(int x,int y,vector<vector<char>>&grid){
            int n=grid.size();
            int m=grid[0].size();

            grid[x][y]='0';
            for(int d=0;d<4;d++){
                int nx=x+dx[d];
                int ny=y+dy[d];

                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]=='1'){
                    grid[nx][ny]='0';
                    dfs(nx,ny,grid);
                }
            }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int island=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    island++;
                    dfs(i,j,grid);
                }
            }
        }
        return island;
    }
};