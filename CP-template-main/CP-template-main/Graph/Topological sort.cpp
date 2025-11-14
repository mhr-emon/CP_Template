//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
 
using namespace std;
//#define op() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pi 3.1415926536
#define pb push_back
#define all(v)((v).begin()), ((v).end())
#define endo '\n'
#define F first
#define S second
#define mp(x, y) make_pair(x, y)
#define gcd(a, b) __gcd(a, b);
#define lcm(a, b)(a * b) / gcd(a, b)
#define sizeofBit(n)(int) log2(n) + 1
#define Kth_bit(n, k)(n >> k & 1);
/*
bool prime(ll n) {if(n<2) return 0; for(ll i=2;i<=sqrt(n);i++){if(n%i==0)return 0;} return 1;}
ll power(ll a,ll b){if(b==0)return 1LL;if(b&1)return a*power(a,b-1);else{ll x=power(a,b/2);return x*x;}}
ll cntdigit(ll n) { string s=to_string(n); return s.size(); }
*/
vector<vector<ll>> adj;
vector<ll> vis, indegree, ans;
 
void dfs(ll n)
{
    queue<ll> q;
    for(ll i=1; i<=n; i++) {
       if(indegree[i] == 0) q.push(i); 
    }
    
    while(!q.empty())
    {
        ll x = q.front();
        q.pop();
        ans.pb(x);
        vis[x] = 1;
        for(auto child : adj[x]) {
          // if(vis[child]) continue;
           indegree[child]--;
           
           vis[child] = 1;
           if(indegree[child] == 0) q.push(child);
        }
    }
}
int main()
{
    ll i, j, x = 0, n, m, p = 0, k, t, q, a, y, b, c, z;
    cin>>n>>m;
    adj = vector<vector<ll>> (n+1);
    vis = vector<ll> (n+1, 0);
    indegree = vector<ll> (n+1, 0);
    for(i=0; i<m; i++) {
       ll u, v;
       cin>>u>>v;
       adj[u].pb(v);
       indegree[v]++;
    }
    
    dfs(n);
    if(ans.size() != n) cout<<"IMPOSSIBLE"<<endo;
    else {
      for(i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
      cout<<endo;
    }
}
