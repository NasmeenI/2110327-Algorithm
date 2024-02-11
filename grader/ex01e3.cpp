#include <iostream>
#include <vector>
using namespace std;

int bsearch(vector<int> v, int x, int start, int stop) {
    if(start == stop) {
        if(v[start] == x) return v[start];
        else if(start == 0) return -1;
        else if(start == v.size()-1 and x > v[start]) return v[start];
        else return v[start-1];
    }
    int m = (start+stop) >> 1;
    if(v[m] >= x) return bsearch(v, x, start, m);
    else return bsearch(v, x, m+1, stop);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x;
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    while(m--) {
        cin >> x;
        cout << bsearch(v, x, 0, n-1) << '\n';
    }
}