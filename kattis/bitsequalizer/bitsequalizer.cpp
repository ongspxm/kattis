#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
using Int = int;
//using Int = long long;
using vi = vector<Int>;
using vvi = vector< vector<Int> >;

/**
 * Solution for problem: bitsequalizer
 *
 * Written by: ongspxm
 *
 * Date: 2018-12-18 16:05:26.640228 UTC
 *
 * Lessons learned: TEXTTEXTTEXT
 */
void solve() {
    Int C; cin >> C;
    REP(c, C){
        string S, T; cin >> S >> T;
        Int n = S.size();

        Int s0=0, s1=0, sQ=0;
        REP(i, n){
            switch(S[i]){
                case '0': s0++; break;
                case '1': s1++; break;
                default: sQ++; break;
            }
        }

        Int t0=0, t1=0, q0=0, q1=0, r=0;
        REP(i, n){
            switch(T[i]){
                case '0':
                    t0++;
                    if(S[i]=='?'){ q0++; }
                    break;
                default:
                    t1++;
                    if(S[i]=='?'){ q1++; }
                    break;
            }

            if (T[i]==S[i]){
                r++;
            }
        }

        Int c0=t0-s0, c1=t1-s1;

        Int ans=c0+c1;
        if (s0+sQ < t0){
            ans = -1;
        } else {
            r += min(c0, q0);
            r += min(c1, q1);
            ans += (n-r)/2;
        }

        cout << "Case " << c+1 << ": " << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
