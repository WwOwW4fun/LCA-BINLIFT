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

const int Max = 200000;
ll parent[Max];
ll dp[200000][30];
ll n;
ll h[200000];
vector <ll> adj[200000];
void dfs(ll u)
{
     for (ll v : adj[u]) {
        if (v == dp[u][0]) continue;
        h[v] = h[u] + 1;

        dp[v][0] = u;
        for (int j = 1; j < 19; ++j)
            dp[v][j] = dp[dp[v][j - 1]][j - 1];

        dfs(v);
    }
}
ll findlca(int u, int v)
{
    if(h[u] != h[v])
    {
        if(h[u] < h[v]) swap(u ,v);
        int k = h[u] -  h[v];
        for(int j = 18; j >= 0; j--)
        {
            if(k >= (1<< j))
            {
                u = dp[u][j];
                k -= (1 << j);
            }
        }
    }
    if (u == v) return u;
    for(int j = 18; j >=0 ; j--)
    {
        if(dp[u][j] != dp[v][j])
        {
            u  = dp[u][j];
            v  = dp[v][j];
        }
    }
    return dp[u][0];
}
int main()
{
    output;
    cin >> n;
    n -= 1;
    while(n --)
    {
        int u ,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);

   int q; cin >> q;
    while(q --)
    {
        int root, u, v; cin >> root >> u >> v;
        int a = findlca(root,u);
        int b = findlca(root,v);
        int c = findlca(u,v);
        cout << (a^b^c) << endl;
    }


}