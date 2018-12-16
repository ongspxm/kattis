#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
using Int = int;
//using Int = long long;
using vi = vector<Int>;
using vvi = vector< vector<Int> >;

/**
 * Solution for problem: ignore
 *
 * Written by: ZZZ
 *
 * Date: 2018-12-16 08:15:32.497556 UTC
 *
 * Lessons learned: TEXTTEXTTEXT
 */
void solve() {
    vi vals = {0,1,2,5,9,8,6};

    Int x;
    while (cin >> x) {
        vi vs;

        while (x>0) {
            vs.push_back(vals[x%7]);
            x /= 7;
        }
        Int s = vs.size();
        REP(i, s){
            cout << vs[i];
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
