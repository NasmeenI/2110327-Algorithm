#include <iostream>
using namespace std;

void recur(vector<vector<int>> &v, int a, int b,int top,int bottom,int left,int right) {
    if(a == 0) {
        v[top][left] = b;
        return;
    }
    
    recur(v, a-1, b  , top                , (bottom+top) >> 1  , left               , (right+left) >> 1);
    recur(v, a-1, b-1, top                , (bottom+top) >> 1  , (left+right+1) >> 1, right            );
    recur(v, a-1, b+1, (top+bottom+1) >> 1, bottom             , left               , (right+left) >> 1);
    recur(v, a-1, b  , (top+bottom+1) >> 1, bottom             , (left+right+1) >> 1, right            );
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a,b;
    cin >> a >> b;
    vector<vector<int>> v((1 << a)+1, vector<int>((1 << a)+1));
    recur(v, a, b, 1, 1 << a, 1, 1 << a);
    for(int i=1;i<=(1<<a);i++) {
        for(int j=1;j<=(1<<a);j++) cout << v[i][j] << ' ';
        cout << '\n';
    }
}