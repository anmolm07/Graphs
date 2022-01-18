/*

Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.


LINK - https://practice.geeksforgeeks.org/problems/bipartite-graph/1

*/

class Solution {
public:
    bool bfs(int node,vector<int>adj[],vector<int>& color)
    {
        color[node]=1;
        queue<int>Q;
        Q.push(node);
        while(!Q.empty())
        {
            int n=Q.front();
            Q.pop();
            for(auto it :adj[n])
            {
                if(color[it]==-1)
                {
                    color[it]=1-color[n];
                    Q.push(it);
                }else if(color[it]==color[n])
                {
                    return false;
                }
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
	            if(!bfs(i,adj,color))
	            {
	                return false;
	            }
	        }
	    }
	    return true;
	}

};
