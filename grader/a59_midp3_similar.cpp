#include <iostream>
using namespace std;

bool similar(string a, string b) {
    if(a.size() == 1) return a == b;
    if(a == b) return true;
    int m = a.size() >> 1;
    return (similar(a.substr(0, m), b.substr(0, m))        and similar(a.substr(m, a.size()), b.substr(m, a.size()))) or 
           (similar(a.substr(0, m), b.substr(m, a.size())) and similar(a.substr(m, a.size()), b.substr(0, m)));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a,b;
    cin >> a >> b;
    cout << (similar(a, b) ? "YES" : "NO");
}