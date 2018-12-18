#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
using Int = int;
//using Int = long long;
using vi = vector<Int>;
using vvi = vector< vector<Int> >;

/**
 * Solution for problem: baloni
 *
 * Written by: ongspxm
 *
 * Date: 2018-12-18 15:41:29.585740 UTC
 *
 * Lessons learned: TEXTTEXTTEXT
 */
void solve() {
    Int v, n; cin >> n;
    vi vs;

    REP(i, n){
        cin >> v;
        vs.push_back(v);
    }

    Int a, c=0;
    while (vs.size()) {
        vi vs2;
        c += 1; a = vs[0];

        n = vs.size();
        REP(i, n){
            if (vs[i]==a) {
                a -= 1;
            } else {
                vs2.push_back(vs[i]);
            }
        }
        vs = vs2;
    }

    cout << c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
