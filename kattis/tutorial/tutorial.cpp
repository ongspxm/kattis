#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
// using Int = int;
using Int = long long;
using vi = vector<Int>;
using vvi = vector< vector<Int> >;

/**
 * Solution for problem: tutorial
 *
 * Written by: ongspxm
 *
 * Date: 2018-12-19 12:29:43.699179 UTC
 *
 * Lessons learned: TEXTTEXTTEXT
 */
void solve() {
    Int m, n, t;
    cin >> m >> n >> t;

    Int x=1;
    switch(t){
        case 1:
            x = 1;
            REP(i, n){
                x *= i+1;
                if (x>m) { break; }
            }
            break;
        case 2:
            x = 2;
            REP(i, n-1){
                x *= 2;
                if (x>m) { break; }
            }
            break;
        case 3:
            x = n*n*n*n;
            break;
        case 4:
            x = n*n*n;
            break;
        case 5:
            x = n*n;
            break;
        case 6:
            x = ceil(log(n)*n/log(2));
            break;
        case 7:
            x = n;
            break;
    }

    if (x<=m) {
        cout << "AC";
    } else {
        cout << "TLE";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
