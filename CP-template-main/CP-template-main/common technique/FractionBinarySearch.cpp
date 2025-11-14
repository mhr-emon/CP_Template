//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
#define op() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pi 3.1415926536
#define pb push_back
#define all(v) ((v).begin()), ((v).end())
#define endo '\n'
#define F first
#define S second
#define mp(x,y) make_pair(x,y)
#define gcd(a,b) __gcd(a,b);
#define lcm(a,b) (a*b)/gcd(a,b)
#define sizeofBit(n) (int)log2(n)+1
#define Kth_bit(n,k) (n >> k & 1);/*
bool prime(ll n) {if(n<2) return 0; for(ll i=2;i<=sqrt(n);i++){if(n%i==0)return 0;} return 1;}
ll power(ll a,ll b){if(b==0)return 1LL;if(b&1)return a*power(a,b-1);else{ll x=power(a,b/2);return x*x;}}
ll cntdigit(ll n) { string s=to_string(n); return s.size(); }*/

int main()
{
    ll i,j,x=0,n,m,p=0,k,t,q,a,y,b,c,z;
    cin>>n>>t;
    vector<ll> v(n);
    double eps = 1e-11;
    ll mnm = 0;
    i = 0;
    while(i < n)
    {
        cin>>v[i];
        mnm = max(v[i],mnm);
        i++;
    }
    double lo = 0, hi = mnm+10;
    while(hi - lo > eps)
    {
        double mid = (lo + hi) / 2.0;
        k = 0;
        for(i=0; i<v.size(); i++)
        {
            a = (double(v[i]) / (double)mid);
            k += int(a);
        }
        if(k < t) hi = mid;
        else
            lo = mid;
    }
    printf("%.9lf\n",hi);
    //cout<<k<<endo;
}


 
