#include <iostream>
using namespace std;

vector<int> seq;

int rec(int n) {
    if(n <= 6) return n;
    else if(n <= 11) return 11 - n + 2;
    auto it = upper_bound(seq.begin(), seq.end(), n) - 1;
    return rec(n - *it) + (it - seq.begin()) + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=1;i<=111111111;i=i*10+1) seq.push_back(i);

    int n;
    cin >> n;
    cout << rec(n);
}