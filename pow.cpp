ll betterpow(ll x, ll n){
    ll ans=1;
    while(n>0) {
        if(n&1) ans*=x;
        x*=x;
        n>>=1;
    }
    return ans;
}

ll modpow(ll x, ll n){
    ll ans=1;
    while(n>0) {
        if(n&1) ans=ans*x%MOD;
        x=x*x%MOD;
        n>>=1;
    }
    return ans;
}
