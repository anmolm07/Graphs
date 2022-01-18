/*
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 

LINK - https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
*/

class Solution {
  public:
    bool dfs(int node,int parent,vector<int>& visited,vector<int>adj[])
    {
        visited[node]=1;
        for(auto it :adj[node])
        {
            if(visited[it]==0)
            {
                if(dfs(it,node,visited,adj))
                return true;
            }else if(it !=parent){
                return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>visited(V,0);
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
            {
                if(dfs(i,-1,visited,adj))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
