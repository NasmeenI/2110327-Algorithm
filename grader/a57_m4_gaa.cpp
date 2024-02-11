#include <iostream>
using namespace std;

vector<int> seq(28);

char rec(int x, int n) {
    if(n <= seq[x-1]) return rec(x-1, n);
    else if(n > seq[x-1] + x + 3) return rec(x-1, n - seq[x-1] - x - 3);
    else if(n == seq[x-1] + 1) return 'g';
    else return 'a';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    seq[0] = 3;
    for(int i=1;i<28;i++) seq[i] = 2*seq[i-1] + i + 3;

    int n, x;
    cin >> n;
    x = lower_bound(seq.begin(), seq.end(), n) - seq.begin();
    cout << rec(x, n);
}