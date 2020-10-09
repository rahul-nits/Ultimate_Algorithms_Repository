#include<bits/stdc++.h>
using namespace std;


void recdfs(vector<int>adj[],int s,stack<int>&st,bool vis[])
{   vis[s]=true;
    for(int u:adj[s])
    {   if(vis[u]==false)
            recdfs(adj,u,st,vis);
    }
    st.push(s);
    
}
void dfs(vector<int>adj[],int V,stack<int>&st)
{       bool vis[V];
        fill(vis,vis+V,false);
        for(int i=0;i<V;i++)
        {   if(vis[i]==false)
            {   recdfs(adj,i,st,vis);}
        }
}
void rec1(vector<int>rev[],int t,bool vis[])
{   vis[t]=true;
    for(int u:rev[t])
    {   if(vis[u]==false)
            rec1(rev,u,vis);
    }
}
int kosaraju(int V, vector<int> adj[])
{      
    stack<int>st;
    dfs(adj,V,st);
    vector<int>rev[V];
    for(int v=0;v<V;v++)
    {   
        for(int u:adj[v])
        {   
            rev[u].push_back(v);
        }
    }
    int count=0;
    bool vis[V];
    fill(vis,vis+V,false);
    while(!st.empty())
    {   
        int v=st.top();
        st.pop();
        if(vis[v]==false)
        {   
            count++;
            rec1(rev,v,vis);
        }
    }
    return count;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int m, n;
        vector<int> adj[a];
        for (int i = 0; i < b; i++) {
            cin >> m >> n;
            adj[m].push_back(n);
        }
        cout << kosaraju(a, adj) << endl;
    }
    return 0;
}
