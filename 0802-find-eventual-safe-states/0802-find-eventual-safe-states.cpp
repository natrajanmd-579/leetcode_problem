class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>revadj(n);
        vector<int>indegree(n,0);

        for(int i=0;i<n;i++){
            for(int it:graph[i]){
                revadj[it].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int>q;

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
            }
        
        vector<int>safe;
        while(!q.empty()){
            int node=q.front();
            q.pop();

            safe.push_back(node);
            for(int adjnode:revadj[node]){
                indegree[adjnode]--;
                if(indegree[adjnode]==0){
                    q.push(adjnode);
                }
            }
        }
        sort(safe.begin(),safe.end());
        return safe;
    }
};