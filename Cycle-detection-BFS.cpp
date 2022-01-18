/*

Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 

LINK - https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

*/

class Solution {
  public:
    bool cycle(int node,vector<int>& visited,vector<int>adj[],int V)
    {
        visited[node]=1;
        queue<pair<int,int>>Q;
        Q.push({node,-1});
        while(!Q.empty())
        {
            int n=Q.front().first;
            int p=Q.front().second;
            Q.pop();
            for(auto it:adj[n])
            {
                if(visited[it]==0)
                {
                    visited[it]=1;
                    Q.push({it,n});
                }
                else if(p!=it)
                {
                    return true;
                }
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
                if(cycle(i,visited,adj,V))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
