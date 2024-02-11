#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a,b;
    cin >> a >> b;
    int arr[b];
    for(int i=0;i<b-a;i++) arr[i] = 0;
    for(int i=b-a;i<b;i++) arr[i] = 1;

    do {
        for(int i=0;i<b;i++) cout << arr[i];
        cout << '\n';
    } while(next_permutation(arr, arr+b));
}