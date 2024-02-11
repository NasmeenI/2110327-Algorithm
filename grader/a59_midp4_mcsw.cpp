#include <iostream>
#define N 200010
#define INF 1010
using namespace std;

int n,w;
vector<int> v(N);

int maxSub(int l, int r) {
    if(l == r) return v[l];

    int m = (l+r) >> 1;
    vector<int> qs;
    qs.push_back(-INF);

    int sum = 0, mx = -INF;
    for(int i=m;i>=max(m-w+2, l);i--) {
        sum += v[i];
        qs.push_back(max(qs.back(), sum));
    }

    sum = 0;
    int mxR = -INF;
    for(int i=m+1;i<=min(m+w, r);i++) {
        sum += v[i];
        mxR = max(mxR, sum);
        mx = max(mx, qs[min(w - i + m, m - l)] + mxR);
    }

    return max(mx, max(maxSub(l, m), maxSub(m+1, r)));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w;
    for(int i=1;i<=n;i++) cin >> v[i];
    cout << maxSub(1, n);
}