class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &it:times){
            int u=it[0];
            int v=it[1];
            int w=it[2];

            adj[u].push_back({v,w});
        }
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto [d,node]=pq.top();
            pq.pop();
            if(d>dist[node]){
                continue;
            }

            for(auto &it:adj[node]){
                int nextnode=it.first;
                int weight=it.second;
            if(dist[node]+weight < dist[nextnode]){
                dist[nextnode]=dist[node]+weight;
                pq.push({dist[nextnode],nextnode});
            }
          }
        }
     int ans=0;
     for(int i=1;i<=n;i++){
        if(dist[i]==INT_MAX){
            return -1;
        }
        ans=max(ans,dist[i]);
     }
     return ans;
    }
};