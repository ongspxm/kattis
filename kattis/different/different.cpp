#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
// using Int = int;
using Int = long long;
using vi = vector<Int>;
using vvi = vector< vector<Int> >;

/**
 * Solution for problem: XXX
 *
 * Written by: ZZZ
 *
 * Date: YYYY-MM-DD
 *
 * Lessons learned: TEXTTEXTTEXT
 */
void solve() {
    Int a, b;
    while (cin >> a >> b) {
        if (a>b) {
            cout << a-b;
        } else {
            cout << b-a;
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
