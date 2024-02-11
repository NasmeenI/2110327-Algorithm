#include <iostream>
using namespace std;

long long p,k,a,b,x;
vector<long long> v;

long long thanos(long long l, long long r) {
    long long cnt = upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);
    if(l == r) return cnt ? b * cnt : a;

    long long m = (l+r) >> 1;
    return min((cnt ? b * cnt * (r - l + 1) : a), thanos(l, m) + thanos(m+1, r));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> p >> k >> a >> b;
    v.resize(k);
    for(int i=0;i<k;i++) cin >> v[i];
    sort(v.begin(), v.end());

    cout << thanos(1, (1<<p));
}