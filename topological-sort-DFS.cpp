/*
Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.

You don't need to read input or print anything. Your task is to complete the function topoSort()  
which takes the integer V denoting the number of vertices and adjacency list as input parameters
and returns an array consisting of a the vertices in Topological order.
As there are multiple Topological orders possible, you may return any of them. If your returned
topo sort is correct then console output will be 1 else 0.


LINK - https://practice.geeksforgeeks.org/problems/topological-sort/1#
*/

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void bfs(int node,vector<int>adj[],vector<int>&visited,vector<int>&res)
	{
	    visited[node]=1;
	    for(auto it :adj[node])
	    {
	        if(visited[it]==0)
	        bfs(it,adj,visited,res);
	    }
	    res.push_back(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>visited(V,0);
	    vector<int>res;
	    for(int i=0;i<V;i++)
	    {
	        if(visited[i]==0)
	        {
	            bfs(i,adj,visited,res);
	        }
	    }
	    reverse(res.begin(),res.end());
	    return res;
	}
};
