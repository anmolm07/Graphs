/*

Given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph..

LINK - https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

*/

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node,vector<int>adj[],vector<int>&res,vector<int>&visited)
    {
        if(visited[node]==1)
        return;
        else{
            res.push_back(node);
            visited[node]=1;
            for(auto i :adj[node])
            {
                if(visited[i]==0)
                {
                    dfs(i,adj,res,visited);
                }
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>res;
        vector<int>visited(V,0);
        dfs(0,adj,res,visited);
        return res;
        
        // Code here
    }
};
