class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
          dist[i][i]=0;
          for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            dist[u][v]=w;
            dist[v][u]=w;
          }
        }

        int city=-1;
        int minrch=INT_MAX;
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[via][j]!=0 && dist[i][via]!=0){
                        dist[i][j]=min(dist[i][j],dist[via][j]+dist[i][via]);
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(i!=j && dist[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=minrch){
                minrch=count;
                city=i;
            }
        }
    return city;
    }
};