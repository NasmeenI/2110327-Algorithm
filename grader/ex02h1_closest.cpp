#include <iostream>
using namespace std;

int distance(pair<int, int> p1, pair<int, int> p2) {
    return (p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second);
}

int closetPair(vector<pair<int, int>> sortedx, vector<pair<int, int>> sortedy) {
    if(sortedx.size() == 1) return 1e9;
    if(sortedx.size() == 2) return distance(sortedx[0], sortedx[1]);

    int m = (sortedx.size() - 1) / 2;
    vector<pair<int, int>> xl, xr, yl, yr;
    for(int i=0;i<=m;i++) xl.emplace_back(sortedx[i]);
    for(int i=m+1;i<sortedx.size();i++) xr.emplace_back(sortedx[i]);
    for(auto [x, y] : sortedy) {
        if(x < xl.back().first) yl.emplace_back(x, y);
        else yr.emplace_back(x, y);
    }

    int mndis = min(closetPair(xl, yl), closetPair(xr, yr));
    vector<pair<int, int>> v;
    for(auto [x, y] : sortedy) 
        if(distance({x, 0}, {xl.back().first, 0}) < mndis) v.emplace_back(x, y); 
    for(int i=0;i<v.size();i++) {
        for(int j=i+1;j<v.size();j++) {
            if(distance({0, v[i].second}, {0, v[j].second}) >= mndis) break;
            mndis = min(mndis, distance(v[i], v[j]));
        }
    }
    return mndis;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x, y;
    cin >> n;
    vector<pair<int, int>> sortedx, sortedy;
    for(int i=0;i<n;i++) {
        cin >> x >> y;
        sortedx.emplace_back(x, y);
        sortedy.emplace_back(y, x);
    }
    sort(sortedx.begin(), sortedx.end());
    sort(sortedy.begin(), sortedy.end());
    for(auto &[y, x] : sortedy) swap(x, y);
    cout << closetPair(sortedx, sortedy);
}