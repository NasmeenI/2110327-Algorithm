#include <iostream>
#define N 1e5+10
#define INF 1e18 + 10
using namespace std;

int n;
vector<long long> v(N), qs(N);

long long maxSub(vector<long long> &v, int l, int r) {
    if(l == r) return v[l];

    int m = (l+r) >> 1;
    long long maxl = -INF, maxr = -INF;
    for(int i=l;i<=m;i++) 
        maxl = max(maxl, qs[m] - qs[i-1]);
    for(int i=m+1;i<=r;i++)
        maxr = max(maxr, qs[i] - qs[m]);
    return max(maxl + maxr, max(maxSub(v, l, m), maxSub(v, m+1, r)));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> v[i];
        qs[i] += v[i] + qs[i-1];
    } 
    cout << maxSub(v, 1, n);
}