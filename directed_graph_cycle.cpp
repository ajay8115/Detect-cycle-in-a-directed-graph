// CODE BY :- AJAY PAL IIT (BHU) VARANASI
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

class Solution
{
public:
    bool iscycle(int src, vector<int> adj[], vector<bool> &vis, vector<int> &stack)
    {
        stack[src] = true;
        if (!vis[src])
        {
            vis[src] = true;
            for (auto i : adj[src])
            {
                if (!vis[i] and iscycle(i, adj, vis, stack))
                {
                    return true;
                }
                if (stack[i])
                {
                    return true;
                }
            }
        }
        stack[src] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {

        vector<int> stack(V, 0);
        vector<bool> vis(V, 0);
        bool cycle = false;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i] and iscycle(i, adj, vis, stack))
            {
                cycle = true;
            }
        }
        if (cycle == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};