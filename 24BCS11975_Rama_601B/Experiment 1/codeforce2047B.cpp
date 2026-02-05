#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n <= 1) {
        cout << s << endl;
        return;
    }

    map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    char max_char = s[0];
    char min_char = s[0];
    int max_val = -1;
    int min_val = n + 1;

    for (auto const& [ch, count] : freq) {
        if (count > max_val) {
            max_val = count;
            max_char = ch;
        }
        if (count <= min_val) {
            min_val = count;
            min_char = ch;
        }
    }

    if (max_char != min_char) {
        for (int i = 0; i < n; i++) {
            if (s[i] == min_char) {
                s[i] = max_char;
                break;
            }
        }
    }

    cout << s << endl;
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