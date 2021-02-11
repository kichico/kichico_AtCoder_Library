#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
#define MOD 1e9+7
#define ALL(x) x.begin(),x.end()

bool isPrime(ll Num){
    ll root=sqrt(Num);
    if(Num==0||Num==1) return false;
    for(ll i=2;i<=root;++i) if(Num%i==0) return false;
    return true;
}
