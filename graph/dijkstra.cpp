#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define INF 1000000000
#define MAXN 50005
#define f first
#define s second
#define mp(a, b) make_pair(a, b)

int n, m, src, d[MAXN];
vector<pii> adj[MAXN];

void dijkstra() {
    for(int i=0; i<n; i++) d[i]=INF;
    d[src]=0;
    priority_queue<pii, vector<pii>, greater<pii> > q;
    q.push(mp(0, src));
    while(!q.empty()) {
        pii cur=q.top();
        q.pop();
        if(d[cur.s]!=cur.f) continue;
        for(auto e:adj[cur.s]) {
            if(d[cur.s]+e.s<d[e.f]) {
                d[e.f]=e.s+d[cur.s];
                q.push(mp(d[e.f], e.f));
            }
        }
    }
}

int main() {
    cin>>n>>m>>src;
    for(int i=0; i<m; i++) {   
        int st, en, di; 
        cin>>st>>en>>di; 
        adj[st].push_back(mp(en, di)); 
        adj[en].push_back(mp(st, di));  
    }
    dijkstra();
    for(int i=0; i<n; i++)
        cout<<(d[i]==INF ? -1:d[i])<<endl;
    return 0;    
}


