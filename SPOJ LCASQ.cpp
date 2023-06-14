/* 
Author : Nguyen Xuan An 
Gmail : xuanan437@gmail.com
*/   
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define for0(i ,l ,r) for(int i = (l); i < (r); ++i)
#define for1(i, l, r) for(int i = (l); i >= (r); --i)
#define for2(v) for(auto it : v)
#define reset(a) memset(a,0,sizeof(a))
#define mem(a) memset(a,-1,sizeof(a))
#define membo(a) memset(a,false,sizeof(a))

#define vi vector<int>
#define vpi vector<pair<int, int>>
#define pii pair<int,int>
#define pll pair<long long, long long >
#define fi first
#define se second
#define prq priority_queue
#define pb push_back

#define output ios::sync_with_stdio(0);cin.tie(0);
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define PI 3.1415926535897932385
#define INF 2e18

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))

const int Max = 100000;
int parent[Max];
//int dp[200000][30];
vector<int> adj[100000];
int h[100000];
int n;
void dfs(int u)
{
    for(int v : adj[u])
    {
        if(v == parent[u]) continue;
        h[v] = h[u] + 1;
        parent[v] = u;
        dfs(v);
    }
}
int solve(int u , int v)
{
     if(h[u] < h[v]) swap(u,v);
     while(h[u] > h[v])
     {
         u = parent[u];
     }
     while(u != v)
     {
         u = parent[u];
         v = parent[v];
     }
     return u;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        while(x --)
        {
            int j; cin >> j;
            adj[j].push_back(i);
            adj[i].push_back(j);
        }
    }
    dfs(0);
    int q; cin >> q;
    while(q --)
    {
        int u, v; cin >> u >>v;
        cout << solve(u, v) << endl;
    }
}
