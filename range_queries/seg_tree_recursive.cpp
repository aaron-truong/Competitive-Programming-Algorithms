#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e5+1;
int n, a[MAXN], t[4*MAXN];
void build(int v=1, int tl=0, int tr=n-1) {
    if(tl==tr) t[v]=a[tl];
    else {
        int tm=(tl+tr)/2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v]=t[v*2]+t[v*2+1];
    }
}
int query(int l, int r, int v=1, int tl=0, int tr=n-1) {
    if(l>r) return 0;
    if(l==tl && r==tr) return t[v];
    int tm=(tl+tr)/2;
    return query(l, min(r, tm), v*2, tl, tm) 
            +query(max(l, tm+1), r, v*2+1, tm+1, tr);
}
void update(int pos, int new_val, int v=1, int tl=0, int tr=n-1) {
    if(tl==tr) t[v]=new_val; 
    else {
        int tm=(tl+tr)/2;
        if(pos<=tm) update(pos, new_val, v*2, tl, tm);
        else update(pos, new_val, v*2+1, tm+1, tr);
        t[v]=t[v*2]+t[v*2+1];
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    build();
    cout<<query(2, 4)<<endl;
    update(2, 10);
    cout<<query(2, 2)<<endl;
}