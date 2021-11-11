#include <bits/stdc++.h>
using namespace std;

int n, arr[100001];

template<class T> struct Seg {
    const T INIT=0; 
    int n; vector<T> seg;
    T FUNC(T a, T b) {return a+b;} 
    void init(int _n) {
        n=_n;
        seg.assign(2*n, INIT);
    }
	void init(int _n, T _a[]) {
        init(_n);
        for(int i=n; i<2*n; i++) seg[i]=_a[i-n];
        for(int i=n-1; i>=1; i--) seg[i]=FUNC(seg[i<<1], seg[i<<1|1]);
    }
    void update(int i, T val) {
        for(seg[i+=n]=val; i>1; i>>=1) 
            seg[i>>1]=FUNC(seg[i], seg[i^1]);
    }
    T query(int l, int r) {
        T ret=INIT;
        for(l+=n, r+=n; l<r; l>>=1, r>>=1) {
            if(l&1) ret=FUNC(ret, seg[l++]);
            if(r&1) ret=FUNC(ret, seg[--r]);
        }
        return ret;
    }
};

int main() {
    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];
    Seg<int> t;
    t.init(n, arr);
    cout<<t.query(0, n)<<endl;
}