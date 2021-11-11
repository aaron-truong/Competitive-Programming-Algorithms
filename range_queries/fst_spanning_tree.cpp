#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

const int MAXN=200001, MAXM=400001;
int n, m, st, t, ds, dt, parent[MAXN], tot=0;
bool used[MAXM];
pair<int, int> edg[MAXM];

int find_set(int i) {
    if(i==parent[i]) return i;
    return parent[i]=find_set(parent[i]);
}
bool union_set(int a, int b) {
    int pa=find_set(a), pb=find_set(b);
    if(pa==pb) return false;
    if(a==st || b==st) {if(ds==0) return false; else ds--;}
    if(a==t || b==t) {if(dt==0) return false; else dt--;}
    parent[pb]=pa;
    tot++;
    return true;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<m; i++) {
        cin>>edg[i].f>>edg[i].s, edg[i].f--, edg[i].s--;
        if(edg[i].s<edg[i].f) swap(edg[i].f, edg[i].s);
    }
    cin>>st>>t>>ds>>dt, st--, t--;
    if(t<st) swap(st, t), swap(ds, dt);
    for(int i=0; i<n; i++) parent[i]=i;
    for(int i=0; i<m; i++) 
        if(edg[i].f!=st && edg[i].f!=t && edg[i].s!=st && edg[i].s!=t) used[i]=union_set(edg[i].f, edg[i].s);
    for(int i=0; i<m; i++) if(!(edg[i].f==st && edg[i].s==t) && !used[i]) used[i]=union_set(edg[i].f, edg[i].s);
    for(int i=0; i<m; i++) if(!used[i]) used[i]=union_set(edg[i].f, edg[i].s);
    if(tot==n-1) {
        cout<<"Yes\n";
        for(int i=0; i<m; i++) if(used[i]) cout<<edg[i].f+1<<" "<<edg[i].s+1<<"\n";
    }
    else cout<<"No\n";
}