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

const int MN=1e5+1;
int n, sz[MN], p[MN], r[MN];
vi g[MN];
int dfs(int cur, int pre) {
    sz[cur]=1;
    for(int v:g[cur]) {
        if(v!=pre && !r[v]) sz[cur]+=dfs(v, cur);
    }
    return sz[cur];
}
int get_centroid(int cur, int ttl, int pre) {
    for(int v:g[cur]) {
        if(v!=pre && !r[v] && sz[v]*2>ttl) {
            return get_centroid(v, ttl, cur);
        }
    }
    return cur;
}
void centroid(int cur, int pre) {
    int c=get_centroid(cur, dfs(cur, -1), -1);
    p[c]=pre, r[c]=1;
    for(int v:g[c]) {
        if(!r[v]) centroid(v, c);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
}