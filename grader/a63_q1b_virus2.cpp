#include <iostream>
using namespace std;

bool virus(vector<int> &v, int l, int r) {
    if(r - l == 1) return true;

    int m = (l+r) >> 1, x = 0, y = 0;
    for(int i=l;i<=m;i++) {
        if(v[i] == 1) x++;;
        if(v[i+m-l+1] == 1) y++;
    }
    if(!(virus(v, l, m) and virus(v, m+1, r) and abs(x - y) <= 1)) cout << '\n' << l << ' ' << r << '\n';
    return (virus(v, l, m) and virus(v, m+1, r) and abs(x - y) <= 1);
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
