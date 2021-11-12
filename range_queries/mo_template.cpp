#include <iostream>
#include <cmath>
using namespace std;
#define MAXN 100001
#define MAXL 320

int n, l, a[MAXN], b[MAXL];
void preprocess() {
    l=(int)sqrt(n+.0)+1;
    for(int i=0; i<n; i++) b[i/l]+=a[i];
}
int query(int left, int right) {
    int sum=0;
    int cl=left/l, cr=right/l;
    if(cl==cr) for(int i=left; i<=right; i++) sum+=a[i];
    else {
        for(int i=left, end=(cl+1)*l-1; i<=end; i++) sum+=a[i];
        for(int i=cl+1; i<=cr-1; i++) sum+=b[i];
        for(int i=cr*l; i<=right; i++) sum+=a[i];
    }
}
int main() {
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    preprocess();
    cout<<query(2, 4);
}