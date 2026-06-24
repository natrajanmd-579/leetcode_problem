class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor=image[sr][sc];
        if(oldcolor==color) return image;
        dfs(sr,sc,image,oldcolor,color);
        return image;
    }

    void dfs(int x,int y,vector<vector<int>>&image,int oldcolor,int newcolor){
        int n=image.size();
        int m=image[0].size();
        image[x][y]=newcolor;

        vector<int>dx={-1,1,0,0};
        vector<int>dy={0,0,-1,1};

        for(int d=0;d<4;d++){
            int nx=x+dx[d];
            int ny=y+dy[d];

            if(nx>=0 && ny>=0 && nx<n && ny<m && image[nx][ny]==oldcolor){
                dfs(nx,ny,image,oldcolor,newcolor);
            }
        }
    }
};