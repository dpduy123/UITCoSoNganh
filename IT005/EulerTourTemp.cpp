#include<bits/stdc++.h>
using namespace std;
#define ll pair<int,int>
#define st first
#define nd second
const int N=1e5+10;
struct info{
    int u,v,c;
} edge[N];
int n,in[N],out[N],G[N*2],timer, D[N*8], lazy[N*8], A[N], pa[N];
vector<ll> ds[N];
int Q, type, u, v, c;
void DFS(int a,int p){
    in[a]=++timer;
    G[timer]=a;

    for(ll v: ds[a]){
        if(v.nd==p) continue;
        A[v.nd]=(A[a]^v.st);
        pa[v.nd]=a;
        DFS(v.nd,a);
    }
    out[a]=++timer;
    G[timer]=a;
}
void build(int id,int l,int r){
    if(l==r){
        D[id]=A[G[l]];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    D[id]=(D[id*2]^D[id*2+1]);
}
void down(int id){
    int t=lazy[id];

    lazy[id*2]^=t;
    D[id*2]^=t;

    lazy[id*2+1]^=t;
    D[id*2+1]^=t;

    lazy[id]=0;
}
void update(int id,int l,int r,int u, int v,int val){
    if(r<u || l>v){
        return;
    }
    if(u<=l && r<=v){
        D[id]^=val;
        lazy[id]^=val;
        return;
    }
    int mid=(l+r)/2;
    down(id);
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    D[id]=(D[id*2]^D[id*2+1]);
}
int get(int id,int l,int r,int u){
    if(r<u || l>u) return 0;
    if(l==r){
        return D[id];
    }
    down(id);
    int mid=(l+r)/2;
    return (get(id*2,l,mid,u)^get(id*2+1,mid+1,r,u));
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>Q;
    for(int i=1; i<n; i++){
        cin>>edge[i].u>>edge[i].v>>edge[i].c;
        ds[edge[i].u].push_back({edge[i].c,edge[i].v});
        ds[edge[i].v].push_back({edge[i].c,edge[i].u});
    }
    DFS(1,1);
    for(int i=1; i<n; i++){
        if(pa[edge[i].u]==edge[i].v) swap(edge[i].u,edge[i].v);

    }
    build(1,1,timer);
}