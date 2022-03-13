#include <bits/stdc++.h>
using namespace std;

// only for min/max

const int MAXN=100001;
int n, h, q, a[MAXN], seg[MAXN*2]={0}, lz[MAXN*2]={0};

template<class T> struct Seg {
	const T INIT=0;
	int n, h;
	vector<T> seg, lz;
	Seg(int _n) {
		n=_n;
		h=(int)log2(n);
		seg.assign(2*n, 0);
		lz.assign(2*n, 0);
	}
	T FUNC(T a, T b) {return max(a, b);}
	void apply(int i, T dif) {
		seg[i]+=dif;
		if(i<n) lz[i]+=dif;
	}
	void build(int i) {
		while(i>1) {
			i>>=1;
			seg[i]=FUNC(seg[i<<1], seg[i<<1|1])+lz[i];
		}
	}
	void push(int p) {
		for(int i=h; i>0; i--) {
			int j=p>>i;
			if(lz[j]) {
				apply(j<<1, lz[j]);
				apply(j<<1|1, lz[j]);
				lz[j]=0;
			}
		}
	}
	void update(int l, int r, T dif) {
		l+=n, r+=n;
		int li=l, ri=r;
		for(; l<r; l>>=1, r>>=1) {
			if(l&1) apply(l++, dif);
			if(r&1) apply(--r, dif);
		}
		build(li), build(ri-1);
	}
	T query(int l, int r) {
		l+=n, r+=n;
		push(l), push(r-1);
		T ret=INIT;
		for(; l<r; l>>=1, r>>=1) {
			if(l&1) ret=FUNC(ret, seg[l++]);
			if(r&1) ret=FUNC(ret, seg[--r]);
		}
		return ret;
	}
};
