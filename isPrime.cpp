bool isPrime(ll Num){
    ll root=sqrt(Num);
    if(Num==0||Num==1) return false;
    for(ll i=2;i<=root;++i) if(Num%i==0) return false;
    return true;
}
