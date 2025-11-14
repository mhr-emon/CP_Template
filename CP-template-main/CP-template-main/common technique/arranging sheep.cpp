int main()
{
    ll i, j, x = 0, n, m, p = 0, k, t, q, a, y, b, c, z;
    cin>>t;
    while(t--)
    {
        cin>>n;
        string st;
        cin>>st;
        vector<ll> v;
        for(i=0; i<n; i++) {
           if(st[i] == '*') v.pb(i);
        }
        x = (v.size()-1) / 2;
        
        ll ans = 0;
        for(i=0; i<v.size(); i++) {
           ans += abs(v[i] - (v[x] - x + i));
          
        }
        cout<<ans<<endo;
    }
}
