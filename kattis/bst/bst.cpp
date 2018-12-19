#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
// using Int = int;
using Int = long long;
using vi = vector<Int>;
using vvi = vector< vector<Int> >;

/**
 * Solution for problem: bst
 *
 * Written by: ongspxm
 *
 * Date: 2018-12-19 12:53:24.592721 UTC
 *
 * Lessons learned: TEXTTEXTTEXT
 */
void solve() {
    Int n; cin >> n;
    vi ss, ds; set<Int> all;
    REP(i, n){
        ss.push_back(0);
        ds.push_back(0);
    }

    set<Int>::iterator t;
    Int x, r, c=0;
    REP(i, n){
        cin >> x;

        if(i>0){
            // check for left
            t = all.lower_bound(x);
            if(t!=all.begin()){
                r = *(--t)-1;
                if(!ss[r]){
                    ss[r] = 1;
                    ds[x-1] = ds[r]+1;
                }
            }

            // check for right
            if(ds[x-1]==0){
                r = *(all.upper_bound(x)) - 1;
                ds[x-1] = ds[r]+1;
            }

            c += ds[x-1];
        }

        all.insert(x);
        cout << c << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
