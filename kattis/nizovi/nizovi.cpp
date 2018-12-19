#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
using Int = int;
//using Int = long long;
using vi = vector<Int>;
using vvi = vector< vector<Int> >;

void sp(Int n) {
    REP(i, n){ cout << " "; }
}

/**
 * Solution for problem: nizovi
 *
 * Written by: ongspxm
 *
 * Date: 2018-12-19 01:35:48.376902 UTC
 *
 * Lessons learned: TEXTTEXTTEXT
 */
void solve() {
    char c, l=0; string ele;
    Int i = 0;
    while(cin >> c){
        switch(c){
            case '{':
                sp(i); cout << '{' << endl;
                i += 2; break;
            case '}':
                if (ele.size()) {
                    sp(i); cout << ele << endl;
                }

                if (l=='}'){ cout << endl; }
                i -= 2; sp(i); cout << '}';
                ele = ""; break;
            case ',':
                if (l!='}') { sp(i); }
                cout << ele << ',' << endl;
                ele = ""; break;
            default:
                ele += c;
                break;
        }

        l = c;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
