#include <iostream>
using namespace std;
#define MAXN 100001

int n, arr[MAXN], bit[MAXN];
void update(int i, int val) {
    for(i++; i<=n;) bit[i]+=val, i+=i&(-i);
}
void construct() {
    for(int i=1; i<=n; i++) bit[i]=0;
    for(int i=0; i<n; i++) update(i, arr[i]);
}
int query(int i) {
    int s=0;
    for(i++; i>0;) s+=bit[i], i-=i&(-i);
    return s;
}
int main() {
    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];
    construct();
    cout<<query(-1)<<"\n";
}