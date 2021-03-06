/*
You are given a network of n nodes, labeled from 1 to n.
You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi),
where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal.
If it is impossible for all the n nodes to receive the signal, return -1.


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

LINK - https://leetcode.com/problems/network-delay-time/

*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector dis(n+1,INT_MAX);
        dis[k]=0;
        bool updated;
        for(int i=0;i<n-1;i++)
        {
            updated=false;
            for(auto x:times)
            {
                int u=x[0];
                int v=x[1];
                int cost=x[2];
            
                if( dis[u]!=INT_MAX  && dis[u]+cost <dis[v])
                {
                    dis[v]=dis[u]+cost;
                    updated=true;
                }
            }
            if(updated==false) break;
        
        }
        int ans=0;
    
        for(int i=1;i<=n;i++)
            ans=max(ans,dis[i]);
    
        if(ans==INT_MAX)
            return -1;
        else
            return ans;
            
    }
};
