ll modpow(ll x, ll n){
    ll ans=1;
    while(n>0) {
        if(n&1) ans=ans*x%MOD;
        x=x*x%MOD;
        n>>=1;
    }
    return ans;
}

ll com(ll n, ll k, vector<ll> fac_n,vector<ll> fac_k){
    if(n==0&&k==0) return 1;
    if(n<k||n<0) return 0;
    ll value=fac_k[n-k]*fac_k[k]%MOD;
    return value*fac_n[n]%MOD;
}



