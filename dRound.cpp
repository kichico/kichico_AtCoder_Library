#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
#define MOD 1e9+7
#define ALL(x) x.begin(),x.end()

double dRound(double x,ll n){
    for(ll i=0;i<n;++i) x*=10;
    x=round(x);
    for(ll i=0;i<n;++i) x/=10;
    return x;
}
