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
 
const ll MAXN = 200001;
 
ll n;
ll segtree[4 * MAXN], v[MAXN];
 
void build(int l = 1, int r = n, int node = 1) {
	if (l == r) segtree[node] = v[l];
	else {
		int mid = (l + r) / 2;
		build(l, mid, node * 2);
		build(mid + 1, r, node * 2 + 1);
		segtree[node] = (segtree[node * 2] + segtree[node * 2 + 1]);
	}
}
 
ll query(int ql, int qr, int l = 1, int r = n, int node = 1) {
    if (qr < l || ql > r) return 0; 
    if (ql <= l && r <= qr) return segtree[node]; 
    int mid = (l + r) / 2;
    return (query(ql, qr, l, mid, node * 2) + query(ql, qr, mid + 1, r, node * 2 + 1));
}
 
void update(int idx, ll val, int l = 1, int r = n, int node = 1) {
    if (l == r) {
        segtree[node] = val;
    } else {
        int mid = (l + r) / 2;
        if (idx <= mid) update(idx, val, l, mid, node * 2);
        else update(idx, val, mid + 1, r, node * 2 + 1);
        segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
    }
}
 
 
int main()
{
    ll i, j, x = 0, m, p = 0, k, t, q, a, y, b, c, z;
    cin>>n>>q;
    for(i=1; i<=n; i++) cin>>v[i];
    build();
    while(q--)
    {
        cin>>a>>b>>c;
        if(a == 1) {
           update (b, c);
        }
        else cout<<query(b, c)<<endo;
    }
}
