#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
using Int = int;
//using Int = long long;
using vi = vector<Int>;
using vvi = vector< vector<Int> >;

/**
 * Solution for problem: snowflakes
 *
 * Written by: ongspxm
 *
 * Date: 2018-12-23 12:10:14.283899 UTC
 *
 * Lessons learned: TEXTTEXTTEXT
 */
using si = set<Int>;
using qi = queue<Int>;

void solve() {
    Int n, T; cin >> T;
    REP(t, T){
        cin >> n;
        si fs; qi qs;

        Int x, l=0, m=0, tmp;
        REP(i, n){
            cin >> x;
            if(fs.count(x)>0){
                while(true){
                    tmp = qs.front(); l--;
                    fs.erase(tmp); qs.pop();
                    if(tmp==x){break;}
                }
            }
            l++;
            fs.insert(x); qs.push(x);

            m = max(m, l);
        }
        cout << m << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
