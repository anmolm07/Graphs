/*
Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.

LINK - https://practice.geeksforgeeks.org/problems/bipartite-graph/1#
*/

class Solution {
public:
    bool dfs(int node,vector<int>adj[],vector<int>& color,int i)
    {
        color[node]=i;
        for(auto it :adj[node])
        {
            if(color[it]==-1)
            {
                if(!dfs(it,adj,color,1-i))
                {
                    return false;
                }
            }else if(color[it]==color[node])
            {
                return false;
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int>color(V,-1);
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
	            if(!dfs(i,adj,color,1))
	            {
	                return false;
	            }
	        }
	    }
	    return true;
	}

};
