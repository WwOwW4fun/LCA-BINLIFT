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
ll dp[Max][30];
ll n;
ll h[Max];
vector <ll> adj[Max];
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
ll findlca(ll u, ll v)
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
ll range(ll u, ll v)
{
    ll cnt = 0;
    if(h[u] != h[v])
    {
        if(h[u] < h[v]) swap(u ,v);
        ll k = h[u] -  h[v];
        for(int j = 18; j >= 0; j--)
        {
            if(k >= (1<< j))
            {
                u = dp[u][j];
                k -= (1 << j);
                cnt += (1 << j);
            }
        }
    }
    if(u != v and h[u] == h[v])
    {
        for(int j = 18; j >=0 ; j--)
        {
            if(dp[u][j] != dp[v][j])
            {
                u  = dp[u][j];
                v  = dp[v][j];
                cnt += 2* (1 << j);
            }
        }
        cnt += 2;

    }
    return cnt;
}
int main()
{
    int q;
    cin >> n >> q;
    n -= 1;
    for0(i,0,n)
    {
        ll x; cin >> x;
        adj[x].push_back(i+2);
        adj[i+2].push_back(x);
    }
    dfs(1);
    while(q --)
    {
        ll root, u, v; cin >> root >> u >> v;
        ll a = findlca(root,u);
        ll b = findlca(root,v);
        ll c = findlca(u,v);
        ll lca = (a^b^c);
        ll x = range(lca,u);
        ll y = range(lca,v);
        ll z = range(lca,root);
        ll ans = INT_MIN;
        ans = max(ans,max(x,max(y,z)));
        cout << ans + 1 << endl;
    }


}