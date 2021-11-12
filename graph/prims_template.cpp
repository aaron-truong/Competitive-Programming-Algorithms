#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp(a, b) make_pair(a, b)

const int MAXN=1e5+1, INF=1<<30;
int n, ttl=0, used[MAXN]={0};
vector<pair<int, int> > graph[MAXN];
pair<int, int> e[MAXN];

void prim() {
    e[0].f=0;
    set<pair<int, int> > q;
    q.insert(mp(0, 0));
    for(int i=0; i<n; i++) {
        int v=q.begin().s;
        u[v]=1;
        ttl+=q.begin().f;
        q.erase(q.begin());
        for(auto j:graph[v]) {
            if(!u[j.s] && j.f<e[j.s].f) {
                q.erase(mp(e[j.s].f, j.s));
                e[j.s]=mp(j.f, v);
                q.insert(mp(j.f, j.s));
            }
        }
    }
    
}