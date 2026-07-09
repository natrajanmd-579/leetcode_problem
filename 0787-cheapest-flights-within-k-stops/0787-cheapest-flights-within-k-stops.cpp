class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &it:flights){
            int u=it[0];
            int v=it[1];
            int cost=it[2];
            adj[u].push_back({v,cost});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();

            int stop=it.first;
            int node=it.second.first;
            int cost=it.second.second;

            if(stop>k){
                continue;
            }

            for(auto &adjnode:adj[node]){
                int nextnode=adjnode.first;
                int edgecost=adjnode.second;
                if(cost+edgecost < dist[nextnode] && stop<=k){
                    dist[nextnode]=cost+edgecost;
                    q.push({stop+1,{nextnode,dist[nextnode]}});
                }
            }
        }
        if(dist[dst]==INT_MAX){
        return -1;}

        return dist[dst];
    }
};