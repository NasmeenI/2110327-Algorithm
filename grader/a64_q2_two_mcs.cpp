#include <iostream>
#define N 500010
using namespace std;

int n;
vector<int> qs(N);

pair<int, int> maxSub(int l, int r) {
    if(l == r) return {qs[l] - qs[0], 0};
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> qs[i];
        qs[i] += qs[i-1];
    }
    maxSub(1, n);
}