#include <bits/stdc++.h>
using namespace std;

int n, q;
template<class T> struct node {
    T val=0; node* c[2];
    node() {c[0]=c[1]=NULL;}
    void update(int ind, T v, int l=0, int r=n-1) {
        if(l==ind && r==ind) {val+=v; return;}
        int mid=(l+r)/2;
        if(ind<=mid) {
            if(!c[0]) c[0]=new node();
            c[0]->update(ind, v, l, mid);
        }
        else {
            if(!c[1]) c[1]=new node();
            c[1]->update(ind, v, mid+1, r);
        }
        val=0;
        for(int i=0; i<2; i++) if(c[i]) val+=c[i]->val;
    }
    T query(int l, int r, int tl=0, int tr=n-1) {
        if(tl>r || tr<l) return 0;
        if(l<=tl && tr<=r) return val;
        int mid=(tl+tr)/2; T res=0;
        if(c[0]) res+=c[0]->query(l, r, tl, mid);
        if(c[1]) res+=c[1]->query(l, r, mid+1, tr);
        return res;
    }
};
node<int> seg;
int main() {
    cin>>n>>q;
    for(int i=0, t, a, b; i<q; i++) {
        cin>>t>>a>>b;
        if(t==0) seg.update(a, b);
		else cout<<seg.query(a, b)<<"\n";
    }
}