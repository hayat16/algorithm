#include<bits/stdc++.h>
using namespace std;
vector<int>node[1005];
int dist[1005];
int bfs(int src)
{
    dist[src]=0;
    queue<int>q;
    q.push(src);
    cout<<"searching way : ";
    while(!q.empty())
    {
        int u=q.front();
        cout<<u<<" ";
        q.pop();
        for(int i=0; i<node[u].size(); i++)
        {
            int v=node[u][i];
            if(dist[v]==-1)
            {
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
}
int main()
{
    int n,e,i,a,b,j;
    memset(dist,-1,sizeof dist);
    cout<<"Enter the number of the node and edge :  ";
    cin>>n>>e;
    for(i=0; i<e; i++)
    {
        cin>>a>>b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    /*adjacency list*/
    cout<<"adjacency list ; "<<endl;
    for(i=1; i<=n; i++)
    {
        cout<<i<<"  : ";
        for(j=0; j<node[i].size(); j++)
        {
            cout<<node[i][j]<<"  ";
        }
        cout<<endl;
    }
    int src=1;
    bfs(src);
    cout<<endl<<"level : ";
    for(i=1; i<=n; i++)
    {
        cout<<dist[i]<<" ";
    }

}
