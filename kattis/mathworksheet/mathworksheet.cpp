#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
using Int = int;
//using Int = long long;
using vi = vector<Int>;
using vvi = vector< vector<Int> >;

/**
 * Solution for problem: mathworksheet
 *
 * Written by: ongspxm
 *
 * Date: 2018-12-19 00:56:33.276365 UTC
 *
 * Lessons learned: TEXTTEXTTEXT
 */
void solve() {
    Int n; cin >> n;
    bool f=true;
    while (n>0) {
        if(!f) {
            cout << endl;
        }
        f = false;

        Int m=0; vi as, ss;
        REP(i, n) {
            Int a, b; char c; cin >> a >> c >> b;

            switch(c){
                case '+': a += b; break;
                case '-': a -= b; break;
                case '*': a *= b; break;
                case '/': a /= b; break;
                default: break;
            }

            Int s = to_string(a).size();
            m = max(s, m);

            as.push_back(a); ss.push_back(s);
        }

        Int cc = 50/(m+1);
        REP(i, (n/cc)+1) {
            bool w=false;
            REP(j, cc){
                Int d = i*cc + j;
                if (d >= n) {
                    break;
                }

                w=true;

                if(j>0){
                    cout << " ";
                }

                REP(k, m-ss[d]){
                    cout << " ";
                }
                cout << as[d];
            }

            if (w) {
                cout << endl;
            }
        }

        cin >> n;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
