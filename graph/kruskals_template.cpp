#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

const int MAXN=1e5+1, MAXM=1e5+1;
int n, m, wt=0, par[MAXN], rank[MAXN];
pair<int, pair<int, int> > e[MAXN];

int find_set(int v) {
    if(v==par[v]) return v;
    return par[v]=find_set(par[v]);
}
void set_union(int a, int b) {
    a=find_set(a), b=find_set(b);
    if(a==b) return;
    if(rank[a]<rank[b]) swap(a, b);
    par[b]=a;
    if(rank[a]==rank[b]) rank[a]++;
}
void kruskals() {
    for(int i=0; i<n; i++) par[i]=i, rank[i]=0;
    sort(e, e+m);
    for(auto i:e) {
        if(find_set(i.s.f)!=find_set(i.s.s)) {
            wt+=i.f;
            set_union(i.s.f, i.s.s);
        }
    }
}