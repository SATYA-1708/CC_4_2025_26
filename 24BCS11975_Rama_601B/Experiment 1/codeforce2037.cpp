#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
 
using namespace std;
 
bool is_composite(int x) {
    if (x < 4) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return true;
    }
    return false;
}
 
void solve() {
    int n;
    cin >> n;
 
    if (n < 4) {
        cout << -1 << endl;
        return;
    }
 
    if (n == 8) {
        cout << "1 8 7 3 6 2 4 5" << endl;
        return;
    }
 
    vector<int> odds, evens;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) evens.push_back(i);
        else odds.push_back(i);
    }
 
    int idx = -1;
    for (int i = 0; i < evens.size(); i++) {
        if (is_composite(odds.back() + evens[i])) {
            idx = i;
            break;
        }
    }
 
    if (idx == -1) {
        cout << -1 << endl;
    } else {
        for (int x : odds) cout << x << " ";
        cout << evens[idx];
        for (int i = 0; i < evens.size(); i++) {
            if (i != idx) cout << " " << evens[i];
        }
        cout << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}