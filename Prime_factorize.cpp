vector<pair<ll,ll>> prime_factorize(ll Num){
    vector<pair<ll,ll>> pr; //pair<primenumber(素数),Exponentiation(べき数)>
    vector<bool> listprime(Num);
    for(ll i=0;i<Num;++i) listprime[i]=true;
    ll root=sqrt(Num);
    ll res=Num;
    for(ll i=2;i<=root;++i){
        ll expnum=0;
        if(listprime[i]) {
            while(res%i==0) {
                res/=i;
                expnum++;
            }
            for(ll j=i*2;j<=root;j+=i) listprime[j]=false;
        }
        if(expnum!=0) pr.emplace_back(make_pair(i,expnum));
    }
    if(res!=1) pr.emplace_back(make_pair(res,1));
    return pr;
}

