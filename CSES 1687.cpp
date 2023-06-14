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

const int Max = 10000000;
int parent[Max];
int dp[300000][30];
int n;
void setup()
{
    for(int i = 1; i <= n ; i++) dp[i][0] =  parent[i];
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j < 19; j ++)
        {
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }
}
int solve(int u, int k)
{
    for(int  i = 18 ; i >= 0 ; i--)
    {
        if(k >= (1 << i))
        {
            u = dp[u][i];
            k -= (1 << i);
        }
    }
    return u;
}
int main()
{
    output;
    int  q; cin >> n >> q;
    for0(i, 0 , n  - 1)
    {
        int x; cin >> x;
        parent[i + 2] = x;
    }
    setup();
    while(q --)
    {
        int u, k; cin >> u >> k;
        if(solve(u, k) == 0) cout << -1 << endl;
        else cout << solve(u, k) << endl;
    }
}