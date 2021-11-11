#include <bits/stdc++.h>
using namespace std;

const int MAXN=2e5+1;
int n, q, a[MAXN], seg[MAXN*4], lz[MAXN*4];

void build(int v=1, int tl=0, int tr=n-1) {
    if(tl==tr) seg[v]=a[tl];
    else {
        int tm=(tl+tr)/2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        seg[v]=seg[v*2]+seg[v*2+1];
    }
}
void update(int l, int r, int dif, int v=1, int tl=0, int tr=n-1) {
    if(lz[v]) {
        seg[v]+=(tr-tl+1)*lz[v];
        if(tl!=tr) lz[v*2]+=lz[v], lz[v*2+1]+=lz[v];
        lz[v]=0;
    }
    if(tl>tr || tl>r || tr<l) return;
    if(tl>=l && tr<=r) {
        seg[v]+=(tr-tl+1)*dif;
        if(tr!=tl) lz[v*2]+=dif, lz[v*2+1]+=dif;
        return;
    }
    int mid=(tl+tr)/2;
    update(l, r, dif, v*2, tl, mid);
    update(l, r, dif, v*2+1, mid+1, tr);
    seg[v]=seg[v*2]+seg[v*2+1];
}
int query(int l, int r, int v=1, int tl=0, int tr=n-1) {
    if(lz[v]) {
        seg[v]+=(tr-tl+1)*lz[v];
        if(tl!=tr) lz[v*2]+=lz[v], lz[v*2+1]+=lz[v];
        lz[v]=0;
    }
    if(tl>tr || tl>r || tr<l) return 0;
    if(tl>=l && tr<=r) return seg[v];
    int mid=(tl+tr)/2;
    return query(l, r, v*2, tl, mid)+query(l, r, v*2+1, mid+1, tr);
}
int main() {
    cin>>n>>q;
    for(int i=0; i<n; i++) cin>>a[i];
	build();
    for(int i=0, t, l, r; i<q; i++) {
        cin>>t>>l>>r;
        if(t==0) {
            int dif; cin>>dif;
			update(l, r, dif);
        }
		else cout<<query(l, r)<<"\n";
    }
}