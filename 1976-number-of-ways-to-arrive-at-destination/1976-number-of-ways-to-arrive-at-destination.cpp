class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
       const int MOD=1e9+7;
       vector<vector<pair<int,int>>>adj(n);
       for(auto &it:roads){
          int u=it[0];
          int v=it[1];
          int w=it[2];
          adj[u].push_back({v,w});
          adj[v].push_back({u,w});
       }
       priority_queue<pair<long long,int>,
                      vector<pair<long long,int>>,
                      greater<pair<long long,int>>>pq;
       
       vector<long long>dist(n,LLONG_MAX);
       vector<int>ways(n,0);
       dist[0]=0;
       ways[0]=1;
       pq.push({0,0});
       while(!pq.empty()){
          auto [d,node]=pq.top();
          pq.pop();
          if(d>dist[node]) continue;
          for(auto &[adjnode,wt]:adj[node]){
              if(dist[node]+wt<dist[adjnode]){
                   dist[adjnode]=dist[node]+wt;
                   ways[adjnode]=ways[node];
                   pq.push({dist[adjnode],adjnode});
              }
              else if(dist[node]+wt==dist[adjnode]){
                 ways[adjnode]=(ways[adjnode]+ways[node]) % MOD;
              }
          }
       }
       return ways[n-1];
    }
};