#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
using Int = int;
//using Int = long long;
using vi = vector<Int>;
using vvi = vector< vector<Int> >;

/**
 * Solution for problem: rockpaperscissors
 *
 * Written by: ongspxm
 *
 * Date: 2018-12-19 11:37:47.474742 UTC
 *
 * Lessons learned: TEXTTEXTTEXT
 */
void solve() {
    Int n, k;
    while(cin >> n >> k){
        vi ws, ds; Int t=k*n*(n-1)/2;
        REP(i, n){ ws.push_back(0); ds.push_back(0); }

        string o1, o2; Int p1, p2;
        REP(i, t){
            cin >> p1 >> o1 >> p2 >> o2;
            if((o1[0]=='r' && o2[0]=='s')
                    || (o1[0]=='p' && o2[0]=='r')
                    || (o1[0]=='s' && o2[0]=='p')){
                ws[p1-1] = ws[p1-1]+1;
            } else if(o1[0]!=o2[0]) {
                ws[p2-1] = ws[p2-1]+1;
            } else {
                ds[p1-1] = ds[p1-1]+1;
                ds[p2-1] = ds[p2-1]+1;
            }
        }

        REP(i, n){
            Int r = (n-1)*k - ds[i];
            if(r>0){
                Int v = round((1000.0*ws[i])/r);
                cout << v/1000 << '.';
                if(v%1000<10){ cout << 0; }
                if(v%1000<100){ cout << 0; }

                cout << v%1000 << endl;
            } else {
                cout << '-' << endl;
            }
        }

        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
