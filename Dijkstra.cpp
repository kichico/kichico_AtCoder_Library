#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>
#include<limits>
#include<bitset>
#include<functional>
#include<type_traits>
#include<queue>
#include<stack>
#include<array>
#include<random>
#include<utility>
#include<cstdlib>
#include<ctime>
#define ALL(x) x.begin(),x.end()
using ll=long long;
using namespace std;

struct Edge{
    ll to,cost;
    Edge() {}
    Edge(ll to, ll costt=0): to(to), cost(cost) {}
};

typedef pair<ll,ll> P;
struct graph{
    const ll INF=numeric_limits<ll>::max();
    vector<vector<Edge>> G;
    ll n;
    graph(ll N) {
        n=N;
        G.resize(n);
    }
    void add_edge(ll from, ll destination, ll cost, ll ticket) {
        G[from].emplace_back(destination,cost,ticket); 
    }
    pair<vector<ll>,vector<ll>> dijkstra(ll start) {
        vector<ll> dist(n,INF);
        vector<ll> path(n,-1);
        priority_queue<P,vector<P>,greater<P>> que;
        dist[start]=0;
        que.emplace(0,start);
        while(!que.empty()){
            P p=que.top();
            que.pop();
            ll v=p.second;
            ll min_dist=p.first;
            if(dist[v]<min_dist) continue;
            for(Edge& edge:G[v]){
                if(dist[edge.to]>dist[v]+edge.cost){
                    dist[edge.to]=dist[v]+edge.cost;
                    que.emplace(dist[v]+edge.cost,edge.to);
                    path[edge.to]=v;
                }
            }
        }
        pair<vector<ll>,vector<ll>> retpair;
        retpair=make_pair(dist,path);
        return retpair;
    }
    vector<ll> getpath(const vector<ll> &rec, ll goal){
        vector<ll> path;
        for(ll i=goal; i!=-1; i=rec[i]) path.push_back(i);
        reverse(ALL(path));
        return path;
    }
    void gridgraph(const vector<vector<ll>> &field, graph& gr, ll ticket) {
        ll height=(ll)field.size();
        ll width=(ll)field[0].size();
        for(ll i=0;i<height;++i){
            for(ll j=0;j<width;++j){
                for(ll t=0;t<ticket;++t){
                    if(i-1>=0) gr.add_edge(i*width+j,(i-1)*width+j,field[i-1][j],ticket);
                    if(i+1<height) gr.add_edge(i*width+j,(i+1)*width+j,field[i+1][j],ticket);
                    if(j-1>=0) gr.add_edge(i*width+j,i*width+j-1,field[i][j-1],ticket);
                    if(j+1<width) gr.add_edge(i*width+j,i*width+j+1,field[i][j+1],ticket);
                }
            }
        }
    }
};



int main(){
    ll height,width,start;
    cin>>height>>width;
    graph g(height*width);
    vector<vector<ll>> field(height,vector<ll>(width,-1));
    ll ticket;
    cin>>ticket;
    for(ll i=0;i<height;++i) for(ll j=0;j<width;++j) cin>>field[i][j];
    g.gridgraph(field,g,ticket);
    auto d=g.dijkstra(0);
    auto path=g.getpath(d.second,17);
    cout<<d.first.back()<<endl;
}