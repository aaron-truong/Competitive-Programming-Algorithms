#include <iostream>
#include <algorithm>

#define MAXN 100001

int n, parent[MAXN], size[MAXN];

int find_set(int v) {
    if (v==parent[v])
        return v;
    return parent[v]=find_set(parent[v]);
}
void make_set(int v) {
    parent[v]=v;
    size[v]=1;
}
void union_sets(int a, int b) {
    a=find_set(a);
    b=find_set(b);
    if(a!=b) {
        if(size[a]<size[b]) swap(a, b);
        parent[b]=a;
        size[a]+=size[b];
    }
}