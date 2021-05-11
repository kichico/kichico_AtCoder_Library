#include "bits/stdc++.h"
#include <chrono>
//using namespace std;
#include <string>
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
template <class T>
std::vector<std::vector<T>> grid;
#define ALL(x) x.begin(),x.end()
#define rep(iter,start,N) for(ll iter=start;iter<N;++iter)

const ll MOD=1e9+7;
const ll INF=1e18;
//#######################################################################
void op(std::vector<ll> vec){
    ll size=(ll)vec.size();
    for(ll i=0;i<size-1;++i) std::cout<<vec[i]<<" ";
    std::cout<<vec.back()<<std::endl;
}

void op(std::vector<std::vector<ll>> vec){
    ll height=(ll)vec.size();
    ll width=(ll)vec[0].size();
    for(ll i=0;i<height;++i) {
        for(ll j=0;j<width-1;++j) std::cout<<vec[i][j]<<" ";
        std::cout<<vec[i].back()<<std::endl;
    }
}
//########################################################################
std::vector<int> factorial(int N){
    unsigned long long sum=1;
    auto start=std::chrono::system_clock::now();
    std::vector<int> fa(1,1);
    //std::cout<<"debug"<<std::endl;
    for(int i=2;i<=N;++i) for(int j=0;j<fa.size();++j){
        int value=fa[j]*i;
        std::string str=std::to_string(value);
        if(fa.size()+j<str.size()) for(int k=fa.size();k<str.size();++k) fa.emplace_back();
        for(auto x:fa) std::cout<<x<<std::endl;
        //std::cout<<"debug"<<std::endl;
        for(int k=0;k<str.size();++k){
            //std::cout<<"here:"<<str[str.size()-k-1]<<std::endl;
            fa[j]*=(str[str.size()-k-1]-'0');
            //if(fa[j]>=10) fa[j+1]+=str[str.size()-k-2]-'0';
        }
    }
    auto end=std::chrono::system_clock::now();
    auto dur = end - start;
    auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
    std::cout << msec << " milli sec"<<std::endl;
    std::reverse(fa.begin(),fa.end());
    return fa;
}


int solve(){
    int N;
    std::cin>>N;
    std::vector<int> res=factorial(N);
    //std::cout<<res[0]<<std::endl;
    for(int i=0;i<res.size();++i) std::cout<<res[i]<<" ";
    std::cout<<std::endl;
    getchar();
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}