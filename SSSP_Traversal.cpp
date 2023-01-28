#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int visited[N] = {0};
vector<int>adj_list[N];
int level[N] = {0};

void BFS(int node)
{

    queue<int>q;
    q.push(node);
    visited[node] = 1;
    level[node] = 0;

    while(!q.empty())
    {
        int head = q.front();
        q.pop();
        // cout<<head<<" ";
        for(int adj_node:adj_list[head])
        {
            if(visited[adj_node] == 0)
            {
                level[adj_node] = level[head] +1;
                visited[adj_node] = 1;
                q.push(adj_node);
            }
        }
    }
}
/*

6 6

0 1
0 2
1 2
2 3
3 4
3 5

*/

int main()
{
    int nodes,edges;
    cin>>nodes>>edges;

    for(int i = 0; i<edges; i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);

    }

    int source = 0;
    BFS(source);
    for(int i = 0; i<edges; i++)
    {
        cout<<"node : "<<i<<" -> level: "<<level[i]<<endl;
    }

    return 0;
}
