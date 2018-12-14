#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
using Int = int;
//using Int = long long;
using vi = vector<Int>;
using vvi = vector< vector<Int> >;

/**
 * Solution for problem: abc
 *
 * Written by: ongspxm
 *
 * Date: 2018-12-14 07:11:48.362128 UTC
 *
 * Lessons learned: TEXTTEXTTEXT
 */
void solve() {
    vi vals = vi();

    Int x;
    REP (i, 3) {
        cin >> x; vals.push_back(x);
    }
    sort(vals.begin(), vals.end());

    string str; cin >> str;
    REP (i, 3) {
        switch (str[i]) {
            case 'A': cout << vals[0]; break;
            case 'B': cout << vals[1]; break;
            case 'C': cout << vals[2]; break;
            default: break;
        }

        if (i<2) {
            cout << " ";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
