#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
//using Int = int;
using Int = long long;
using vi = vector<Int>;
using vvi = vector< vector<Int> >;

/**
 * Solution for problem: stockbroker
 *
 * Written by: ZZZ
 *
 * Date: 2018-12-14 21:31:49.868454 UTC
 *
 * Lessons learned: TEXTTEXTTEXT
 */
void solve() {
    Int last, n; cin >> n;
    Int amt = 100;

    REP(i, n){
        Int v; cin >> v;
        if (i>0 && v>last) {
            Int cnt = amt/last;
            if (cnt > 100000) {
                cnt = 100000;
            }

            amt += (v-last)*cnt;
        }
        last = v;
    }

    cout << amt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
