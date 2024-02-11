#include <iostream>
using namespace std;

bool virus(vector<int> &v, int l, int r) {
    if(r - l == 1) return (v[l] == 0 and v[r] == 1);

    int m = (l+r) >> 1;
    vector<int> v2 = v;
    for(int i=l;i<=(l+m)/2;i++) swap(v2[i], v2[l+m-i]);
    return ((virus(v2, l, m) or virus(v, l, m)) and virus(v, m+1, r));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;
    while(n--) {
        vector<int> v(1 << k);
        for(int i=0;i<(1 << k);i++) cin >> v[i];
        cout << (virus(v, 0, (1 << k)-1) ? "yes" : "no") << '\n';
    }
}