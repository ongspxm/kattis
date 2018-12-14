#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
using Int = int;
//using Int = long long;
using vi = vector<Int>;
using vvi = vector< vector<Int> >;

/**
 * Solution for problem: downtime
 *
 * Written by: ongspxm
 *
 * Date: 2018-12-14 07:29:42.303473 UTC
 *
 * Lessons learned: TEXTTEXTTEXT
 */
void solve() {
    Int N, k; cin >> N >> k;
    priority_queue< Int, vector<Int>, greater<Int> > times;

    REP (n, N) {
        Int x; cin >> x;
        if (times.size() > 0 && times.top() <= x) {
            times.pop();
        }
        times.push(x+1000);
    }

    Int size = times.size();
    cout << size/k + 1*(size%k > 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
