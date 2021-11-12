#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001
#define INIT 0
#define FUNC(a, b) (a)^(b)

int n, q, cur=0;
int parent[MAXN], depth[MAXN], value[MAXN], hev[MAXN], head[MAXN], pos[MAXN], seg[MAXN<<1];
vector<int> graph[MAXN];

int dfs(int v) {
    int s=1, mcs=0;
    for(int c:graph[v]) {
        if(c!=parent[v]) {
            parent[c]=v, depth[c]=depth[v]+1;
            int cs=dfs(c);
            s+=cs;
            if(cs>mcs) mcs=cs, hev[v]=c;
        }
    }
    return s;
}
int decompose(int v, int h) {
    head[v]=h, pos[v]=cur++;
    if(hev[v]+1) decompose(hev[v], h);
    for(int c:graph[v]) if(c!=parent[v] && c!=hev[v]) decompose(c, c);
}
void construct() {
    for(int i=0; i<n; i++) seg[pos[i]+n]=value[i];
    for(int i=n-1; i>=1; i--) seg[i]=FUNC(seg[i<<1], seg[i<<1|1]);
}
void update(int i, int val) {
    for(seg[i+=n]=val; i>1; i>>=1) seg[i>>1]=FUNC(seg[i], seg[i^1]);
}
int seg_query(int l, int r) {
    int ret=seg[r];
    for(l+=n, r+=n; l<r; l>>=1, r>>=1) {
        if(l&1) ret=FUNC(ret, seg[l++]);
        if(r&1) ret=FUNC(ret, seg[--r]);
    }
    return ret;
}
int query(int a, int b) {
    int ret=INIT;
    for(; head[a]!=head[b]; b=parent[head[b]])
        if(depth[head[a]]>depth[head[b]]) swap(a, b);
            ret=FUNC(ret, seg_query(pos[head[b]], pos[b]));
    if(depth[a]>depth[b]) swap(a, b);
    ret=FUNC(ret, seg_query(pos[a], pos[b]));
    return ret;
}
int main() {
    cin>>n;
    for(int i=0; i<n; i++) cin>>value[i];
    for(int i=0, a, b; i<n-1; i++) {
        cin>>a>>b, a--, b--;
        graph[a].push_back(b), graph[b].push_back(a);
    }
    parent[0]=0;
    for(int i=0; i<n; i++) hev[i]=-1;
    dfs(0);
    decompose(0, 0);
}
