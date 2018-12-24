#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
using Int = int;
// using Int = long long;
using vi = vector<Int>;
using vvi = vector< vector<Int> >;

/**
 * Solution for problem: snowflakes
 *
 * Written by: ZZZ
 *
 * Date: 2018-12-23 04:32:59.538400 UTC
 *
 * Lessons learned: TEXTTEXTTEXT
 */

using si = set<Int>;
using qi = queue<Int>;
using mii = unordered_map<Int, Int>;

void solve() {
    Int T; cin >> T;
    REP(t, T){
        si fs; qi qs; mii pos;
        Int m=0,s=0;

        Int N; cin >> N;
        REP(n, N){
            Int x; cin >> x;
            if(fs.count(x)>0){
                Int d = pos[x]-s;
                REP(i, d){
                    fs.erase(qs.front());
                    qs.pop(); s++;
                }
            }
            fs.insert(x); qs.push(x);
            pos[x] = n;
            m = max(m, (Int)fs.size());
        }
        cout << m << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
