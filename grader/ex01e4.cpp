#include <iostream>
#include <cmath>
using namespace std;

int mod(int m, long long n, int k) {
    if(n == 1) return m % k;

    int x = mod((m*m) % k, n/2, k) % k;
    return n % 2 == 0 ? x : (x * (m % k)) % k;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m,k;
    long long n;
    cin >> m >> n >> k;
    cout << mod(m, n, k);
}