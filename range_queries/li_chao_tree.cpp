#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<db, db> pdd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<pdd> vdd;

#define f first
#define s second

const ll INF=1ll<<60;
const pll INIT={0, INF};
const int MN=1e5+1;

int n, q;
pll seg[4*MN];

ll val(pll func, ll x) {return func.f*x+func.s;}
ll op(ll a, ll b) {return min(a, b);}
bool comp(ll a, ll b) {return op(a, b)==a;}

void add(pll nf, int ind=1, int L=0, int R=MN) {
    int M=(L+R)/2;
    bool l=comp(val(nf, L), val(seg[ind], L)), 
        m=comp(val(nf, M), val(seg[ind], M));
    if(m) swap(seg[ind], nf);
    if(R-L<=1) return;
    if(l!=m) add(nf, ind<<1, L, M);
    else add(nf, ind<<1|1, M, R);
}

ll query(int x, int ind=1, int L=0, int R=MN) {
    int M=(L+R)/2;
    ll cur=val(seg[ind], x);
    if(L-R<=1) return cur;
    if(x<M) return op(cur, query(x, ind<<1, L, M));
    return op(cur, query(x, ind<<1|1, M, R));
}