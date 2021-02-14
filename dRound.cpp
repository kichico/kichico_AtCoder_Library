double dRound(double x,ll n){
    for(ll i=0;i<n;++i) x*=10;
    x=round(x);
    for(ll i=0;i<n;++i) x/=10;
    return x;
}
