#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
// using Int = int;
using Int = long long;
using vi = vector<Int>;
using vvi = vector< vector<Int> >;

/**
 * Solution for problem: woodcutting
 *
 * Written by: ZZZ
 *
 * Date: 2018-12-14 23:09:45.847911 UTC
 *
 * Lessons learned: TEXTTEXTTEXT
 */
void solve() {
    Int T; cin >> T;
    REP(t, T){
        priority_queue<Int, vi, greater<Int> > cs;
        Int N, time=0; cin >> N;
        REP(n, N){
            Int w, s, tot=0; cin >> w;
            REP(i, w){
                cin >> s; tot += s;
            }
            cs.push(tot);
        }

        REP(n, N){
            time += cs.top() * (N-n);
            cs.pop();
        }

        cout << float((time*10e8)/N)/10e8 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
