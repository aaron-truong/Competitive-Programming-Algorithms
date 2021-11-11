#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 100001

int n, m, q, height[MAXN], f[MAXN];
vector<int> graph[MAXN], euler, seg;

int min_height(int a, int b) {return height[a]<height[b] ? a:b;}
void tour(int cur, int pre, int h) {
    height[cur]=h;
    f[cur]=euler.size();
    euler.push_back(cur);
    for(int v:graph[cur])
        if(v!=pre) {
            tour(v, cur, h+1);
            euler.push_back(cur);
        }
}
void construct() {
    tour(0, -1, 0);
    m=euler.size();
    seg.resize(m<<1);
    for(int i=m; i<2*m; i++) seg[i]=euler[i-m];
    for(int i=m-1; i>=1; i--) seg[i]=min_height(seg[i<<1], seg[i<<1|1]);
}
int query(int l, int r) {
    int ret=euler[l];
    for(l+=m, r+=m; l<r; l>>=1, r>>=1) {
        if(l&1) ret=min_height(ret, seg[l++]);
        if(r&1) ret=min_height(ret, seg[--r]);
    }
    return ret;
}
int lca(int a, int b) {
    int l=f[a], r=f[b];
    if(l>r) swap(l, r);
    return query(l, r+1);
}
int main() {
    cin>>n>>q;
    for(int i=0, a, b; i<n-1; i++) {
        cin>>a>>b, a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    construct();
    for(int i=0, a, b; i<q; i++) {
        cin>>a>>b, a--, b--;
        cout<<lca(a, b)+1<<"\n";
    }
}
