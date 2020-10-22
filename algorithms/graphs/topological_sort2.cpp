#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

void sortit(const vector<list<int> >& adjlist, int i, stack<int>& sorted, int vis[])
{
    vis[i]= 1;
    for(auto it = adjlist[i].begin(); it!=adjlist[i].end(); it++)
    {
        if(vis[*it]==0)
        {
            sortit(adjlist, *it, sorted, vis);
        }
    }
    cout << i << endl;
    sorted.push(i);
}

void toposort(const vector<list<int> >& adjlist, int v)
{
    int i, vis[v];
    for(i=1; i<=v; i++)
        vis[i]=0;
    stack<int> sorted;
    for(i=1; i<=v; i++)
    {
        if(vis[i]==0)
            sortit(adjlist, i, sorted, vis);
    }
    while(!sorted.empty())
    {
        cout << sorted.top();
        sorted.pop();
    }
}

int main()
{
    int v, e, v1, v2;
    cin >> v >> e;
    vector<list<int> > adjlist(v+1);
    for(int i=1; i<=v; i++)
    {
        cin >> v1 >> v2;
        adjlist[v1].push_back(v2);
    }
    toposort(adjlist, v);
}
