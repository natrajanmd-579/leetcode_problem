class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>>dis(m,vector<int>(n,-1));
        queue<pair<int,int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dis[i][j]=0;
                }
            }
        }

        vector<int>dx={-1,1,0,0};
        vector<int>dy={0,0,-1,1};

        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && ny>=0 && nx<m && ny<n && dis[nx][ny]==-1){
                    dis[nx][ny]=dis[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
       return dis; 
    }
};