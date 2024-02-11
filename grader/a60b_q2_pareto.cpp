#include <bits/stdc++.h>
#define N 1e5+10
using namespace std;

int n;
vector<int> x(N),y(N);

vector<int> frontier(int l, int r) {
    if(l == r) return {l};

    int m = (l+r) >> 1;
    vector<int> vl = frontier(l, m);
    vector<int> vr = frontier(m+1, r);
    vector<int> temp;
    for(int i=vl.size()-1; i>=0; i--) {
        if(vl[i].second <= vr.back().second) break;
        temp.push_back(vl[i]);
    }
    for(int i=temp.size()-1; i>=0; i--) vr.push_back(temp[i]);
    return temp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<pair<int, int>> v;
    for(int i=0;i<n;i++) {
        cin >> x[i] >> y[i];
        v.emplace_back(x[i], y[i]);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++) x[i] = v[i].first, y[i] = v[i].second;
    cout << frontier(0, v.size()-1).size();
}
