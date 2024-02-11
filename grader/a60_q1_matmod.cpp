#include <iostream>
using namespace std;

vector<vector<int>> mul(vector<vector<int>> &a, vector<vector<int>> &b, int k) {
    vector<vector<int>> temp(2, vector<int>(2));
    temp[0][0] = ( (a[0][0]*b[0][0]) % k + (a[0][1]*b[1][0]) % k ) % k;
    temp[0][1] = ( (a[0][0]*b[0][1]) % k + (a[0][1]*b[1][1]) % k ) % k;
    temp[1][0] = ( (a[1][0]*b[0][0]) % k + (a[1][1]*b[1][0]) % k ) % k;
    temp[1][1] = ( (a[1][0]*b[0][1]) % k + (a[1][1]*b[1][1]) % k ) % k;
    return temp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n,k;
    vector<vector<int>> v(2, vector<int>(2)), ans(2, vector<int>(2, 0));
    cin >> n >> k;
    for(int i=0;i<2;i++) for(int j=0;j<2;j++) {
        cin >> v[i][j];
        if(i == j) ans[i][j] = 1;
    }

    while(n > 0) {
        if(n % 2 == 1) ans = mul(v, ans, k);
        v = mul(v, v, k);
        n /= 2;
    }
    
    for(int i=0;i<2;i++) for(int j=0;j<2;j++) cout << ans[i][j] << ' ';
}